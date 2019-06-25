// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex10
// jichunli@uw.edu 1531264

// This file contains implementation of Vector class

#include <iostream>
#include "Vector.h"

namespace vector333 {

Vector::Vector() : x_(0), y_(0), z_(0) {}

Vector::Vector(const float x, const float y, const float z) :
  x_(x), y_(y), z_(z) {}

Vector::Vector(const Vector& copyme) {
  x_ = copyme.x_;
  y_ = copyme.y_;
  z_ = copyme.z_;
}

Vector::~Vector() {}

Vector& Vector::operator=(const Vector& v) {
  if (this != &v) {
    this->x_ = v.x_;
    this->y_ = v.y_;
    this->z_ = v.z_;
  }
  return *this;
}

Vector Vector::operator+(const Vector& v) {
  Vector temp;
  temp.x_ = this->x_ + v.x_;
  temp.y_ = this->y_ + v.y_;
  temp.z_ = this->z_ + v.z_;
  return temp;
}

Vector Vector::operator-(const Vector& v) {
  Vector temp;
  temp.x_ = this->x_ - v.x_;
  temp.y_ = this->y_ - v.y_;
  temp.z_ = this->z_ - v.z_;
  return temp;
}

Vector& Vector::operator+=(const Vector& v) {
  this->x_ += v.x_;
  this->y_ += v.y_;
  this->z_ += v.z_;
  return *this;
}

Vector& Vector::operator-=(const Vector& v) {
  this->x_ -= v.x_;
  this->y_ -= v.y_;
  this->z_ -= v.z_;
  return *this;
}

Vector Vector::operator*(const double k) {
  Vector temp;
  temp.x_ = this->x_ * k;
  temp.y_ = this->y_ * k;
  temp.z_ = this->z_ * k;
  return temp;
}

float Vector::operator*(const Vector& v) {
  float result = 0.0;
  result += this->x_ * v.x_;
  result += this->y_ * v.y_;
  result += this->z_ * v.z_;
  return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
  out << "(" << v.x_ << "," << v.y_ << "," << v.z_ << ")";
  return out;
}

Vector operator*(const double k, const Vector& v) {
  Vector temp;
  temp.x_ = v.x_ * k;
  temp.y_ = v.y_ * k;
  temp.z_ = v.z_ * k;
  return temp;
}

}  // namespace vector333

