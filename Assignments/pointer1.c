//
// Created by Quinn on 2.9.2025.
//
#include <stdio.h>
int main () {
    int anton = 42;
    int *anton_pointer = &anton;

    printf("You entered %d\n", anton);
    printf("The address of anton: %d\n", anton_pointer);
    // *anton_pointer --> get the value of the pointer
    printf("The value of anton_pointer: %d\n", *anton_pointer);
    // &anton_pointer --> get the address of the pointer
    printf("The address of anton_pointer: %d\n", &anton_pointer);
    return 0;
}