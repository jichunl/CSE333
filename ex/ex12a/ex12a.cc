// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex12a
// jichunli@uw.edu 1531264

// This is the file contains a program that reads a text file whose filename is
// given as a single command-line argument. It reads and counts the individual
// words in the file, and after reading the entire file, it will print a sorted
// list of the words and the number of times each word appears in the file. 
// Each word should be written on a separate output line with the word first
// followed by a single space and the number of occurrences.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

// print the word and the number of occurrence of the corresponding word
void print(const pair<string, int>& mapPair);

int main(int argc, char** argv) {
  // check if number of input is 2
  if (argc != 2) {
    cerr << "ERROR: Invalid Input" << endl;
    return EXIT_FAILURE;  // return failure
  }
  string filename = argv[1];
  string word;
  map<string, int> wordMap;
  // open the file
  ifstream fd(filename);
  // check if open successfully
  if (fd.is_open()) {
    // read by words
    while (fd >> word) {
      // check current word is inside of map
      if (wordMap.count(word) > 0) {
        wordMap[word]++;
      } else {
        // if not, insert it into map
        wordMap.insert(pair<string, int>(word, 1));
      }
    }
  } else {
    cerr << "ERROR: Unable to open file" << endl;
    return EXIT_FAILURE;  // return failure
  }
  for_each(wordMap.begin(), wordMap.end(), print);  // print each element out
  // close the file
  fd.close();
  return EXIT_SUCCESS;  // return success
}

void print(const pair<string, int>& mapPair) {
  cout << mapPair.first << " " << mapPair.second << endl;
}
