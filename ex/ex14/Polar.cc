// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This is the implementation of the Polar object

#include <cmath>
#include <string>
#include "Polar.h"

using namespace std;

Polar::Polar(double r, double theta) {
  r_ = r;
  theta_ = theta;
}

double Polar::Distance(const Polar &other) {
  double r1 = r_;
  double r2 = other.r_;
  double angle = theta_ - other.theta_;
  return sqrt(r1 * r1 + r2 * r2 - 2 * r1 * r2 * cos(angle));
}

string Polar::ToString() const {
  return ("Polar (radius = " + to_string(r_) +  ", angle = "
          + to_string(theta_) + ")");
}
