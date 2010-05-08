/* Copyright 2010 Teemu Vasama. Ords is distributed under the GPLv3.
 *
 * This file is part of Ords.
 *
 *   Ords is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 3
 *   as published by the Free Software Foundation.
 *
 *   Ords is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License 
 *	 (the LICENSE file) along with Ords.
 *	 If not, see <http://www.gnu.org/licenses/>.
 */

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
