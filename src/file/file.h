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
// 		src/file/file.h -- Working with files
// 	
// Dummy for including settings and data access classes
// 

#ifndef FILE_H
#define FILE_H

#include "../data/data.h"
#include "../utils/utils.h"

#include "settings.h"
#include "plaintext.h"

/* The following functions are dummies that just call the real functions, 
 * implemented for the distant possibility of doing a MySQL-interface. For now, 
 * they don't really do anything
 */
 
void writeData(string filename, string data);
string readData(string filename);

#endif
