// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex1a
// jichunli@uw.edu

// This is a C program that tests whether or not the following data types are
// passed by reference or by value, and prints what it discovers to the
// terminal: a double, an array of ints

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

static void double_modifier(double src);
static void array_modifier(int32_t src[]);

int main(int argc, char* argv[]) {
    // test if double is pass-by-value or pass-by-ref
    double double_src = 1.0;
    double_modifier(double_src);
    if (double_src == 1.0) {
        printf("double: pass-by-value\n");
    } else {
        printf("double: pass-by-reference\n");
    }

    // test if int array is pass-by-value or pass-by-ref
    int32_t array_src[3] = {1, 2, 3};
    array_modifier(array_src);
    if (array_src[0] == 1 && array_src[1] == 2 && array_src[2] == 3) {
        printf("array of ints: pass-by-value\n");
    } else {
        printf("array of ints: pass-by-reference\n");
    }
}

// modifies a double variable
static void double_modifier(double src) {
    src++;
}

// modifies a int array variable
static void array_modifier(int32_t src[]) {
    src++;
}
