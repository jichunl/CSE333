// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This is the header file that defines a purely virtual class called Coordinate
// that represents an abstract 2-dimensional coordinate. This class have a pure
// virtual method called ToString that returns a string representation.

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <string>

using namespace std;

class Coordinate {
 public:
  // pure virtual function ToString; default is empty
  virtual string ToString() const = 0;
};

#endif  // _COORDINATE_H_

