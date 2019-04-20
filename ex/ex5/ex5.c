// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex5
// jichunli@uw.edu

// This file contains several tests for functions in Vector.c and Vector.h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "Vector.h"

#define ORIGIN_SIZE 4  // origin test vector length
#define NEW_SIZE 10   // test vector length

// Print the elements in the vector on a line.
static void PrintIntVector(vector_t v);

int main(int argc, char *argv[]) {
  uint32_t i;
  vector_t v = VectorCreate(ORIGIN_SIZE);

  if (v == NULL)  // check for malloc error
    return EXIT_FAILURE;

  for (i = 0; i < NEW_SIZE; ++i) {  // Place some elements in the vector.
    int *x = (int*)malloc(sizeof(int));
    if (x == NULL)  // check for malloc error
      return EXIT_FAILURE;
    *x = i;
    element_t old;
    bool set_flag = VectorSet(v, i, x, &old);
    if (!set_flag)
      return EXIT_FAILURE;
  }

  PrintIntVector(v);

  // deallocate space on heap
  element_t curr;
  for (i = 0; i < NEW_SIZE; i++) {
    curr = VectorGet(v, i);
    free(curr);
  }
  VectorFree(v);

  return EXIT_SUCCESS;
}

static void PrintIntVector(vector_t v) {
  uint32_t i;
  size_t length;

  assert(v != NULL);

  length = VectorLength(v);

  if (length > 0) {
    printf("[%d", *((int*)VectorGet(v, 0)));
    for (i = 1; i < VectorLength(v); ++i)
      printf(",%d", *((int*)VectorGet(v, i)));
    printf("]\n");
  }
}

