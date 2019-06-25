// Copyright [2019] <Jichun Li> [copyright]
// CSE 333 Spring 2019
// ex9
// jichunli@uw.edu 1531264

// This is the header file of IntPair class.

#include <cstdint>

#ifndef _INTPAIR_H_
#define _INTPAIR_H_

// This object contains two private instance variables of int64_t x and y
// The object can be constructed using constructor with two fields
// The instance variable could be accessed by Get function, and the values can
// be change by Set function
class IntPair {
 public:
    // constructor: construct a new IntPair object with given fields
    IntPair(const int64_t x, const int64_t y);

    // returns two int64_t through output parameters
    void Get(int64_t* x_ptr, int64_t* y_ptr) const;

    // sets the value of two fields into x_new and y_new
    void Set(int64_t x_new, int64_t y_new);

 private:
    // private instance vairable
    int64_t x_;
    int64_t y_;
};

#endif  // _INTPAIR_H_

