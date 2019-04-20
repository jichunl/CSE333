// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex4
// jichunli@uw.edu

// This is the header file containing function prototype of NthPrime() and
// comments on how to use this function

#ifndef EX_EX4_NTHPRIME_H_

#define EX_EX4_NTHPRIME_H_
#include <stdint.h>

// Accepts a ordinal number n in uint16_t and returns Nth prime number in
//      uint64_t
// Parameter:
//      uint16_t n: the ordinal number of the prime number that will be
//                  returned (the ordinal number starts from 1)
// Returned value:
//      a uint64_t value which represents the Nth prime number
// Error Handling:
//      input parameter n should be with in the range of 1 to UINT16_MAX; if
//          this rule is violated, the function would print out an error
//          message and return 0
//      returned value should not exceed UINT64_MAX; if this rule is violated,
//          the function would print out an error message and return 1
uint64_t NthPrime(uint16_t n);

#endif  // EX_EX4_NTHPRIME_H_

