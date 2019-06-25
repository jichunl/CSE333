// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This is the header file for the subclass of Coordinate that represents a 2D
// polar coordinate. This class contains functinos ToString and Distance.

#ifndef _POLAR_H_
#define _POLAR_H_

using namespace std;

#include <string>
#include "Coordinate.h"

class Polar : public Coordinate{
 public:
  // constructor of Polar object with initial values
  Polar(double r, double theta);

  // calculates the distance between the object and the reference of a second
  // Polar object. The distance returned is a double
  virtual double Distance(const Polar& other);

  // returns the string representation of the Polar object
  virtual string ToString() const;

  // destructor
  virtual ~Polar() {}

 private:
  // private fields
  double r_;  // radius
  double theta_;  // angle
};

#endif  // _POLAR_H_

