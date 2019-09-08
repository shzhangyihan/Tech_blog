#define PY_SSIZE_T_CLEAN
#ifdef __APPLE__
#include <Python/Python.h>
#elif __linux__
#include <Python.h>
#endif
#include <stdio.h>

typedef struct pyFunc{
   PyObject_HEAD
   int (*ptr)(unsigned int);
   int test;
} Callback_Func;

static PyTypeObject Callback_Func_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "callback_name",           /* tp_name */
    sizeof(Callback_Func),     /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "Callback objects",        /* tp_doc */
};

extern "C"
PyObject* callback(Callback_Func* self, PyObject* args, PyObject* kwargs) {
    printf("In c++ PyObject before actually calling the callback function");
    unsigned int input;
    static char *kwlist[] = {"input"};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "I", kwlist, &input)) {
        return NULL;
    }

    int cret = self->ptr(input);
    PyObject * ret = PyLong_FromLong(cret);
    return ret;
}

int test_callback(unsigned int input) {
    printf("This is the test callback function, the input is %d\n", input);
    return 100;
}

int main() {
    printf("start cpp function\n");
    // python load module
    Py_Initialize();
    PyObject * sys = PyImport_ImportModule("sys");
    PyObject * path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));
    PyObject * ModuleString = PyString_FromString((char*) "py_function");
    PyObject * Module = PyImport_Import(ModuleString);
    PyObject * Dict = PyModule_GetDict(Module);

    // python load functions
    PyObject * PrintFunc = PyDict_GetItemString(Dict, "python_test");
    PyObject * PrintResult = PyObject_CallObject(PrintFunc, NULL);
    PyObject * ReturnFunc = PyDict_GetItemString(Dict, "return_test");
    PyObject * ReturnResult = PyObject_CallObject(ReturnFunc, NULL);
    printf("Result of call: %u\n", (unsigned int) PyInt_AsLong(ReturnResult));

    // python try load callback functions
    Callback_Func* python_function_pointer = PyObject_New(Callback_Func, &Callback_Func_Type);
    python_function_pointer->ptr = test_callback;
    python_function_pointer->test = 120;
    PyObject* args = PyTuple_New(2);
    PyTuple_SetItem(args, 0, (PyObject *)python_function_pointer);
    PyTuple_SetItem(args, 1, (PyObject *)callback);

    PyObject * CallbacmFunc = PyDict_GetItemString(Dict, "test_callback");
    PyObject * CallbackResult = PyObject_CallObject(CallbacmFunc, args);
    Py_Finalize();
}
