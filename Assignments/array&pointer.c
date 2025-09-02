//
// Created by Quinn on 2.9.2025.
//
#define ARRAY_SIZE 5
#include <stdio.h>
int sum(int *values, int length);

int main(void) {
    int grades[ARRAY_SIZE];
    int i, result = 0;

    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter a number: ");
        scanf("%d", &grades[i]);
    }
    result = sum(grades, ARRAY_SIZE);
    printf("sum of grades is: %d\n", result);

}

int sum(int *values, int length) {
    int result = 0;


    for (int i = 0; i < length; i++) {
        result += values[i];
    }
    return result;
}