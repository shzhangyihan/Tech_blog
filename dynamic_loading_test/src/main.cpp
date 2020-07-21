#include <dlfcn.h>

#include <iostream>

#include "shape.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Need to provide .so path\n");
        exit(-1);
    }
    std::cout << "Path for .so file: " << argv[1] << std::endl;
    shape *a = new square;
    a->PrintName();

    void *hndl = dlopen(argv[1], RTLD_NOW);
    if (hndl == NULL) {
        std::cout << "wut?" << std::endl;
        std::cerr << dlerror() << std::endl;
        exit(-1);
    }

    typedef shape *(*func_ptr_t)(void);
    func_ptr_t mkr = (func_ptr_t)dlsym(hndl, "maker");
    shape *b = (mkr)();
    b->PrintName();
}