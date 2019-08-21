#define PY_SSIZE_T_CLEAN
#include <Python/Python.h>
#include <stdio.h>

int main() {
    printf("start cpp function\n");
    Py_Initialize();
    PyObject * sys = PyImport_ImportModule("sys");
    PyObject * path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));
    PyObject * ModuleString = PyString_FromString((char*) "py_function");
    PyObject * Module = PyImport_Import(ModuleString);
    PyObject * Dict = PyModule_GetDict(Module);
    PyObject * Func = PyDict_GetItemString(Dict, "python_test");
    PyObject * Result = PyObject_CallObject(Func, NULL);
}
