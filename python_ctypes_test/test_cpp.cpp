#define PY_SSIZE_T_CLEAN
#ifdef __APPLE__
#include <Python/Python.h>
#elif __linux__
#include <Python.h>
#endif

#include <stdio.h>

extern "C" {
    int try_test() {
        printf("Hey I am in c!\n");
    }
}
