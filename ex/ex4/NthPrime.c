// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex4
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "NthPrime.h"


// Checks if the input parameter num in uint64_t is a prime number; if num is a
//      prime number, returns 1; if not, returns 0;
// Parameter:
//      uint64_t num: the number in uint64_t that will be check if is a prime
//                    number or not
// Returned value:
//      an int value that represents if num is prime number or not; 1 for prime
//          number, 0 for non-prime number
int IsPrime(uint64_t num);

uint64_t NthPrime(uint16_t n) {
    // varifies if the input parameter n is valid; if n is not within the range
    // between 1 to UINT16_MAX, print out an error message and return 0
    if (n < 1 || n > UINT16_MAX) {
        printf("ERROR: input parameter n is invalid\n");
        return 0;
    }

    uint64_t curr_num = 0;
    uint64_t order = 0;
    while (order < n) {
        curr_num++;
        if (IsPrime(curr_num)) {
            order++;
        }
    }

    // checks if the output value is out of range; if curr_num is larger than
    // UINT64_MAX, print out an error message and return 1
    if (curr_num > UINT64_MAX) {
        printf("ERROR: resulting value exceeds boundary\n");
        return 1;
    }

    return curr_num;
}

int IsPrime(uint64_t num) {
    if (num < 2) {  // smallest prime number is 2
        return 0;
    }
    for (int i = 2; i < num; i++) {  // i is initialized to 2 as 2 is the first
                                     //     prime number
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
