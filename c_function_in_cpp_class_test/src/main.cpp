#include <dlfcn.h>

#include <iostream>

#include "test.h"

int main() {
    test t1(1);
    test t2(2);

    t1.inc();
    t1.inc();
    t1.inc();
    t2.inc();
    t1.inc();
    t2.inc();
    t2.inc();
}