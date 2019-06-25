// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex14
// jichunli@uw.edu

// This file contains the test for Coordinate class, Polar class and Cartesian
// class

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Coordinate.h"
#include "Cartesian.h"
#include "Polar.h"

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307

using namespace std;

int main(int argc, char** argv) {
  // testing Cartesian
  Cartesian c1(0, 0);
  Cartesian c2(3, 4);
  double dist_c = c1.Distance(c2);
  cout << "Testing Cartesian coordinates" << endl;
  cout << c1.ToString() << endl;
  cout << c2.ToString() << endl;
  cout << "Expected distance: 5" << endl;
  cout << "Actual distance: "<< dist_c << endl;
  cout << "Testing Cartesian done" << endl;
  cout << "-----------------------" << endl;

  Polar p1(0, 0);
  Polar p2(2, PI/6);
  double dist_p = p1.Distance(p2);
  cout << "Testing Polar coordinates" << endl;
  cout << p1.ToString() << endl;
  cout << p2.ToString() << endl;
  cout << "Expected distance: 2" << endl;
  cout << "Actual distance: "<< dist_p << endl;
  cout << "Testing Polar done" << endl;
}
