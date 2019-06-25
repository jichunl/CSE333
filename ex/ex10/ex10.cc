// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex10
// jichunli@uw.edu 1531264

// This file contains tests for Vector class

#include <iostream>
#include "Vector.h"

using namespace vector333;

int main(int argc, char** argv) {
  // testing construtors and stream output
  Vector v1;
  std::cout << "expecting (0,0,0) : " << v1 << std::endl;
  Vector v2(1, 2, 3);
  std::cout << "expecting (1,2,3) : " << v2 << std::endl;
  Vector v3(v2);
  std::cout << "expecting (1,2,3) : " << v3 << std::endl;

  // testing assignment, addition and subtraction
  v2 = Vector(4, 5, 6);
  v1 = v2;
  std::cout << "expecting (4,5,6) : " << v1 << std::endl;
  v1 = v2 + v3;
  std::cout << "expecting (5,7,9) : " << v1 << std::endl;
  v3 = v2 - v1;
  std::cout << "expecting (-1,-2,-3) : " << v3 << std::endl;

  // testing updating assignment
  v3 += Vector(1, 1, 1);
  v1 -= Vector(2, 2, 2);
  std::cout << "expecting (0,-1,-2) : " << v3 << std::endl;
  std::cout << "expecting (3,5,7) : " << v1 << std::endl;

  // testing multiplication
  float scaler = v1 * v2;
  std::cout << "expecting 84 : " << scaler << std::endl;
  Vector v4;
  v4 = v3 * 0.5;
  std::cout << "expecting (0,-0.5,-1) : " << v4 << std::endl;
  Vector v5;
  v5 = 0.5 * v4;
  std::cout << "expecting (0,-0.25,-0.5) : " << v5 << std::endl;

  return EXIT_SUCCESS;
}
