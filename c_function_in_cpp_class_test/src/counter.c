#include <stdio.h>

int counter = 0;

int count() {
    printf("%d\n", counter);
    counter++;
    return counter;
}