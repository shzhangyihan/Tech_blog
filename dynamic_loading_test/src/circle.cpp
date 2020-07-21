#include "circle.h"

#include <stdio.h>

void circle::PrintName() { printf("circle\n"); }

extern "C" {
shape* maker() {
    printf("maker\n");
    return new circle;
}
}