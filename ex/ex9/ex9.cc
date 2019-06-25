// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex9
// jichunli@uw.edu 1531264

// This file contains a test of whether IntPair object is passed by value of
// passed by reference

#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "IntPair.h"

// This is the function that modifies the IntPair object to determine if IntPair
// is passed by value or passed by reference. If the instance variable of main
// is changed then it is passed by reference; otherwise it is passed by value
static void Test(IntPair pair);

int main(int argc, char** argv) {
  IntPair sample(5, 8);
  Test(sample);
  int64_t x_temp, y_temp;
  sample.Get(&x_temp, &y_temp);

  std::cout << "IntPair is passed by ";
  if (x_temp == 5 && y_temp == 8) {
    std::cout << "value" << std::endl;
  } else {
    std::cout << "reference" << std::endl;
  }
  return EXIT_SUCCESS;
}

static void Test(IntPair pair) {
  int64_t x_val, y_val;
  pair.Get(&x_val, &y_val);
  pair.Set(x_val + 1, y_val + 1);
}

