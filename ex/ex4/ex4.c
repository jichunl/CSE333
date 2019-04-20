// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex4
// jichunli@uw.edu

// This file contains tests for function NthPrime() in the main function
// Since the largest possible output is 350377, which is smaller than
// UINT64_MAX, the boundary check for output value will not be tested

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "NthPrime.h"

int main() {
    printf("Testing correctness of function NthPrime()\n");

    // Test 1: Invalid input
    //      passing 0 as the value for ordinal number of the prime number, this
    //      should trigger the invalid input error
    printf("Test case 1: invalid input: 0\n");
    if (NthPrime(0) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed: expected error: invalid input\n");
        return EXIT_FAILURE;
    }

    // Test 2: Small inputs
    //      passing small valid number as inputs to see if the outputs are
    //      correct
    printf("Test case 2: small valid inputs: %d %d %d\n", 1, 2, 3);
    if ((NthPrime(1) == 2) && (NthPrime(2) == 3) && (NthPrime(3) == 5)) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed: incorrect output values\n");
        return EXIT_FAILURE;
    }

    // Test 3: Large valid inputs
    //      passing large valid number as inputs to see if the outputs are
    //      correct
    printf("Test case 3: large valid inputs: %d %d %d\n", 30000, 40000, 50000);
    if ((NthPrime(30000) == 350377) && (NthPrime(40000) == 479909) &&
        (NthPrime(50000) == 611953)) {
            printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed: incorrect output values\n");
        return EXIT_FAILURE;
    }

    // Test 4: Largest valid input
    //      passing largest valid number as input to see if the output is
    //      correct
    printf("Test case 4: largest valid input: %d\n", UINT16_MAX);
    uint64_t temp = NthPrime(UINT16_MAX);
    if (temp == 821603) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed: incorrect output value:\n");
        return EXIT_FAILURE;
    }

    printf("All tests passed\n");
    return EXIT_SUCCESS;
}

