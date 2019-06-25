// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This is the header file for subclass of Coordinate called Cartesian that
// represents a 2D cartesian coordinate (i.e., one with x and y values). It
// contains methods called ToString and Distance.

#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <string>
#include "Coordinate.h"

using namespace std;

class Cartesian : public Coordinate {
 public:
  // constructor with initial values
  Cartesian(double x, double y);

  // calculates the distance between the object and a second Cartesian point
  // object passed by reference as an argument, the distance returned is a
  // double
  double Distance(const Cartesian &other);

  // returns the string representation of the object
  virtual string ToString() const;

  // destructor
  virtual ~Cartesian() {}

 private:
  // private fields
  double x_, y_;
};

#endif  // _CARTESIAN_H_

