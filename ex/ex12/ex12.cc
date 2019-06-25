// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex12
// jichunli@uw.edu 1531264

// This program prompts the user to type in 10 doubles,
// reads those doubles into a vector of doubles,
// sorts the vector, and then prints out the sorted vector.

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Read the type T object from input stream.
// exit(EXIT_FAILURE) after printing out a helpful error message
// if detects conversion or EOF conditions.
template <typename T> T ReadValue(istream& in);

int main(int argc, char** argv) {
  cout << "Input 10 doubles:" << endl;
  vector<double> buf;

  double input;
  for (int i = 0; i < 10; i++) {
    input = ReadValue<double>(cin);
    buf.push_back(input);
  }

  sort(buf.begin(), buf.end());
  cout << "Your sorted doubles are:" << endl;

  for (int i = 0; i < 10; i++) {
    cout << buf[i] << endl;
  }

  return EXIT_SUCCESS;
}

template <typename T> T ReadValue(istream& in) {
  T input;
  in >> input;
  if (in.eof()) {  // reached EOF
    cout << "Reached EOF" << endl;
    exit(EXIT_FAILURE);
  }

  if (in.fail()) {  // conversion error
    cout << "Conversion error" << endl;
    exit(EXIT_FAILURE);
  }

  return input;
}
