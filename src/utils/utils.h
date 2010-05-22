/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
