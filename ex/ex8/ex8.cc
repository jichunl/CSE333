// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex8
// jichunli@uw.edu 1531264

// This program would prompt the user for a positive interger, and then prints
//    out all integers that are factors of that integer

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdint>

using std::cin;  // using namespace
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char** argv) {
  string prompt("Which positive integer would you like me to factorize?");
  cout << prompt << " ";
  int64_t num = 0;
  cin >> num;

  if (num < 1) {  // invalid input
    cerr << "Non-positive input" << endl;
    return EXIT_FAILURE;
  }

  for (int64_t i = 1; i < num; i++) {
    if (num % i == 0) {
      cout << i << " ";
    }
  }
  cout << num << endl;  // adding the number itself as a factor
  return EXIT_SUCCESS;
}
