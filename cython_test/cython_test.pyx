
cdef int dummy_rand_caller(void *user_func):
    return (<object>user_func)()

cdef extern from "cython_test_cpp.cpp":
    ctypedef int (*rand_caller)(void *user_func)
    void setup()
    void inc()
    int get_counter()
    void loop()
    void register_rand(rand_caller caller, void * usr_f)

def py_setup():
    setup()

def py_inc():
    inc()

def py_get_counter():
    return get_counter()

def py_loop():
    loop()

def py_register_rand(f):
    register_rand(dummy_rand_caller, <void*>f)