#pragma once
#include <stdio.h>

int counter;
typedef int (*rand_caller)(void *user_func);
rand_caller caller_local;
void * usr_f_local;

void setup() {
    counter = 0;
}

void inc() {
    counter = counter + 1;
}

int get_counter() {
    return counter;
}

void loop() {
    printf("hey %d\n", caller_local(usr_f_local));
}

void register_rand(rand_caller caller, void * usr_f) {
    caller_local = caller;
    usr_f_local = usr_f;
}