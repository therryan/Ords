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
// 		src/cli/args.h -- Parsing CLI arguments
// 	
// Takes care of parsing and executing proper things according to the args
//

#ifndef ARGS_H
#define ARGS_H 

#include <fstream>

#include "../file/file.h"
#include "../data/data.h"
#include "../utils/utils.h"

// If should continue, return true
bool parseArgs(int argc, char *argv[]);

// A namespace that contains all the functions that take care of a certain switch
namespace args 
{
	//void add(string content);
	void help();
	void read(string target);
	void version();
}

#endif
