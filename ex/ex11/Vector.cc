// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex11
// jichunli@uw.edu 1531264

// This file contains implementations for Vector class

#include <iostream>
using namespace std;
#include "./Vector.h"

namespace vector333 {

Vector::Vector() {
  coord_ = new float[3];
  if (coord_ == nullptr) {
    cout << "Error: not enough memory" << endl;
    exit(EXIT_FAILURE);
  }
  coord_[0] = coord_[1] = coord_[2] = 0;
}

Vector::Vector(const float x, const float y, const float z) {
  coord_ = new float[3];
  if (coord_ == nullptr) {
    cout << "Error: not enough memory" << endl;
    exit(EXIT_FAILURE);
  }
  coord_[0] = x;
  coord_[1] = y;
  coord_[2] = z;
}

Vector::Vector(const Vector &other) {
  coord_ = new float[3];
  if (coord_ == nullptr) {
    cout << "Error: not enough memory" << endl;
    exit(EXIT_FAILURE);
  }
  coord_[0] = other.coord_[0];
  coord_[1] = other.coord_[1];
  coord_[2] = other.coord_[2];
}

Vector::~Vector() {
  delete coord_;
}

Vector &Vector::operator=(const Vector &other) {
  if (this != &other) {
    coord_[0] = other.coord_[0];
    coord_[1] = other.coord_[1];
    coord_[2] = other.coord_[2];
  }
  return *this;
}

Vector &Vector::operator+=(const Vector &other) {
  coord_[0] += other.coord_[0];
  coord_[1] += other.coord_[1];
  coord_[2] += other.coord_[2];
  return *this;
}

Vector &Vector::operator-=(const Vector &other) {
  coord_[0] -= other.coord_[0];
  coord_[1] -= other.coord_[1];
  coord_[2] -= other.coord_[2];
  return *this;
}

double operator*(const Vector &a, const Vector &b) {
  double result = 0;
  result += a.coord_[0] * b.coord_[0];
  result += a.coord_[1] * b.coord_[1];
  result += a.coord_[2] * b.coord_[2];
  return result;
}

Vector operator*(const double k, const Vector &v) {
  Vector temp(k * v.coord_[0], k * v.coord_[1], k * v.coord_[2]);
  return temp;
}

Vector operator*(const Vector &v, const double k) {
  Vector temp(k * v.coord_[0], k * v.coord_[1], k * v.coord_[2]);
  return temp;
}

ostream& operator<<(ostream &out, const Vector &v) {
  out << "(" << v.coord_[0] << "," << v.coord_[1] << "," << v.coord_[2] << ")";
  return out;
}

Vector operator+(const Vector &a, const Vector &b) {
  Vector temp = a;
  temp += b;
  return temp;
}

Vector operator-(const Vector &a, const Vector &b) {
  Vector temp = a;
  temp -= b;
  return temp;
}

}  // namespace vector333

