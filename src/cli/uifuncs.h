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
// 		src/cli/uifuncs.cpp
// 	
// Contains the functions that ui's parse() calls
//

#ifndef UIFUNCS_H
#define UIFUNCS_H 

#include <iomanip>

#include "../data/data.h"
#include "../utils/utils.h"

using std::setw;

namespace ui
{
	void ask(string language = "",  bool reverse = false);
	void open(string file = "");
	void newDict(string title = "");
	void use(string title = "");
	void define(string choice = "");
		void defDefinition(Definition &def);
		bool defDt(DefinitionTerm &dt);
		
	void list();
		void listFile(string file);
		
	void listDicts();
	void help();
}

#endif
