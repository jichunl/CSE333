// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex5
// jichunli@uw.edu

// This file contains the implementations of functions in Vector.h

#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include "Vector.h"

// Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);

vector_t VectorCreate(size_t n) {
  vector_t v = (vector_t) malloc(sizeof(struct vector_t));
  if (v == NULL)
    return NULL;

  v->arry = (element_t*) malloc(n*sizeof(element_t));
  if (v->arry == NULL)
    return NULL;

  // initialize the vector
  v->length = n;
  for (size_t i = 0; i < n; i++)
    v->arry[i] = NULL;
  return v;
}

void VectorFree(vector_t v) {
  assert(v != NULL);
  free(v->arry);
  free(v);
}

bool VectorSet(vector_t v, uint32_t index, element_t e, element_t *prev) {
  assert(v != NULL);

  if (index >= v->length) {
    size_t newLength = index+1;

    element_t* newArray = ResizeArray(v->arry, v->length, newLength);
    if (newArray == NULL)  // check for malooc error
      return false;

    free(v->arry);
    v->arry = newArray;
    v->length = newLength;
  }

  // get the content before change
  *prev = v->arry[index];

  // change the content
  v->arry[index] = e;

  return true;
}

element_t VectorGet(vector_t v, uint32_t index) {
  assert(v != NULL);
  assert(index < v->length);
  return v->arry[index];
}

size_t VectorLength(vector_t v) {
  assert(v != NULL);
  return v->length;
}

static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
  uint32_t i;
  size_t copyLen = oldLen > newLen ? newLen : oldLen;
  element_t *newArry;

  assert(arry != NULL);

  newArry = (element_t*)malloc(newLen*sizeof(element_t));

  if (newArry == NULL)
    return NULL;

  // Copy elements to new array
  for (i = 0; i < copyLen; ++i)
    newArry[i] = arry[i];

  // Null initialize rest of new array.
  for (i = copyLen; i < newLen; ++i)
    newArry[i] = NULL;

  return newArry;
}

