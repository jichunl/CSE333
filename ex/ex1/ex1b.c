// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex1b
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

static void CopyAndSort(int32_t src[], int32_t dest[], uint32_t length);
static void PrintArray(int32_t array[], uint32_t length);
static void Swap(int32_t array[], uint32_t index);

int main(int argc, char** argv) {
    int32_t src[11] = {3, 2, -5, 7, 13, 4, 1, 7, 8, -8, 6};
    int32_t dest[11];
    uint32_t length = 11;

    // sort and copy result to dest
    CopyAndSort(src, dest, length);

    // print dest
    PrintArray(dest, length);
    return EXIT_SUCCESS;
}

// This function accepts two arrays of int32_t's, and an array length iterates
// through the entries of the first array and use insertion sort to insert the
// entries into the second array, in non-decreasing sorted order.
static void CopyAndSort(int32_t src[], int32_t dest[], uint32_t length) {
    for (uint32_t i = 0; i < length; i++) {
        dest[i] = src[i];
        Swap(dest, i);
    }
}

// This function is a helper function for CopyAndSort. It takes in an int32_t
// array and uint32_t index which represents the max index in dest array. Ot
// would recursively swap the entries in the array from back to front until max
// index is 0.
static void Swap(int32_t array[], uint32_t index) {
    if (index > 0) {
        int32_t curr = array[index];
        int32_t prev = array[index - 1];
        if (curr < prev) {
            array[index] = prev;
            array[index - 1] = curr;
            Swap(array, index - 1);
        }
    }
}

// function for print out an array
static void PrintArray(int32_t array[], uint32_t length) {
    for (uint32_t i = 0; i < length; i++) {
        printf("%" PRId32 " ", array[i]);
    }
    printf("\n");
}
