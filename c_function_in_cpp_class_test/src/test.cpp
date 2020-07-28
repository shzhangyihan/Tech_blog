#include "test.h"

#include <dlfcn.h>

#include <iostream>

void test::inc() {
    std::cout << id << ": " << std::endl;
    count_fn();
}

test::test(int id) {
    this->id = id;
    void *hndl = dlmopen(LM_ID_NEWLM, "./build/src/libcounter.so", RTLD_NOW);
    if (hndl == NULL) {
        std::cerr << dlerror() << std::endl;
        exit(-1);
    }
    count_fn = (func_ptr_t)dlsym(hndl, "count");
}
