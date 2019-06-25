// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex11
// jichunli@uw.edu 1531264

// This file contains tests for the vector class

#include <iostream>
#include "./Vector.h"

using namespace vector333;

int main(int argc, char** argv) {
  // test for construtor and << operator
  Vector v1;
  std::cout << "expecting (0,0,0) : " << v1 << std::endl;
  Vector v2(2, 3, 1);
  std::cout << "expecting (2,3,1) : " << v2 << std::endl;
  Vector v3(v2);
  std::cout << "expecting (2,3,1) : " << v3 << std::endl;

  // test for = assignment, + and - operator
  v2 = Vector(3, 4, 3);
  v1 = v3 = v2;
  std::cout << "expecting (3,4,3) : " << v1 << std::endl;
  v3 = v1 + v2;
  v1 = v2 - v3;
  std::cout << "expecting (6,8,6) : " << v3 << std::endl;
  std::cout << "expecting (-3,-4,-3) : " << v1 << std::endl;

  // test for += and -=
  v1 += Vector(1, 1, 1);
  v3 -= Vector(2, 2, 4);
  std::cout << "expecting (4,6,2) : " << v3 << std::endl;
  std::cout << "expecting (-2,-3,-2) : " << v1 << std::endl;

  // test for three kinds of multiplication: v*v, v*k, k*v
  float scaler = v2 * v3;
  std::cout << "expecting 42 : " << scaler << std::endl;
  Vector v4 = v3 * 0.5;
  std::cout << "expecting (2,3,1) : " << v4 << std::endl;
  Vector v5 = 0.5 * v4;
  std::cout << "expecting (1,1.5,0.5) : " << v5 << std::endl;

  return EXIT_SUCCESS;
}
