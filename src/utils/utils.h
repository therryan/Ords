// 
// 		src/utils/utils.h -- Misc utilities
// 	
// Contains several useful little utilities
//

#ifndef UTILS_H
#define UTILS_H 

#include <cstdlib>
#include "using.h"

using std::rand;

// Splits a string and return the tokens as a vector of strings
vector<string> split(const string& str, string delimiter);

// Prints all of the contents of a given vector
string printVector(const vector<string>& vec);

// Reads an integer from the stream properly (by making sure it's a number etc.)
// Optionally can display a message
int getInt(string msg = "");

// Return a random integer in the range 0...max
int getRand(int max);

#endif
