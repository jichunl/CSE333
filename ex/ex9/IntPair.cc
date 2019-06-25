// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex9
// jichunli@uw.edu 1531264

// This file contains the implementation of IntPair object

#include "IntPair.h"
#include <cstdint>

IntPair::IntPair(const int64_t x, const int64_t y) : x_(x), y_(y) {}

void IntPair::Get(int64_t* x_ptr, int64_t* y_ptr) const {
  *x_ptr = x_;
  *y_ptr = y_;
}

void IntPair::Set(int64_t x_new, int64_t y_new) {
  x_ = x_new;
  y_ = y_new;
}

