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
// 		src/utils/using.h -- Contains all "using std::X" statements
// 	
// A dummy file that includes the basics and brings them from the std-namespace
//

#ifndef USING_H
#define USING_H 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::vector;

using std::map;

using std::string;

using std::stringstream;

using std::time;

using std::getenv;

#endif
