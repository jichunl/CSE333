// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This is the implementation of the Cartesian class

#include <cmath>
#include <string>
#include "Cartesian.h"

using namespace std;

Cartesian::Cartesian(double x, double y) {
  x_ = x;
  y_ = y;
}

double Cartesian::Distance(const Cartesian &other) {
  double horizontal = other.x_ - x_;
  double vertical = other.y_ - y_;
  return sqrt(horizontal * horizontal + vertical * vertical);
}

string Cartesian::ToString() const {
  return ("Cartesian(" + to_string(x_) + ", " + to_string(y_) + ")");
}

