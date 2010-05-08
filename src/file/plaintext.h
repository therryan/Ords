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
//  	src/file/plaintext.h -- Working with data in plaintext files
//
// Writing and reading a string to and from a plaintext file
//

#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <fstream>

#include "../data/data.h"
#include "../utils/using.h"

using std::ifstream;
using std::ofstream;
using std::ios;

void writePlaintext(string filename, string data);
string readPlaintext(string filename);

#endif
