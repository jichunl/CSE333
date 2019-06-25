// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex10
// jichunli@uw.edu 1531264

// This is the header file for class Vector

#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace vector333 {

class Vector {
 public:
  // constructor
  Vector();  // default constructor
  Vector(const float x, const float y, const float z);  // with initial values
  Vector(const Vector& copyme);  // copy constructor

  // destructor
  ~Vector();

  // override the =, +, -, +=, -=, * operators
  // assignment
  Vector& operator=(const Vector& v);
  // updating assignment
  Vector& operator+=(const Vector& v);
  Vector& operator-=(const Vector& v);
  // addition and subtraction
  Vector operator+(const Vector& v);
  Vector operator-(const Vector& v);
  // multiplication
  Vector operator*(const double k);  // vector multiplied by k
  float operator*(const Vector& v);  // dot product

  friend Vector operator*(const double k, const Vector &v);
  // print out fields of vector to cout
  friend std::ostream& operator<<(std::ostream &out, const Vector &v);

 private:
  // instance variables
  float x_;
  float y_;
  float z_;
};

}  // namespace vector333

#endif  // _VECTOR_H_


