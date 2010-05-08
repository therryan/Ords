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
// 		src/misc/init.h -- init and deinit
// 	
// Starts and ends the program, loads/saves appropriate files etc.
//

#ifndef INIT_H
#define INIT_H 

#include "../data/data.h"
#include "../utils/utils.h"

// Initializes the program, returns true if everything went fine
bool init();

// Deinitializes the program, also return true if all is OK
bool deinit();		

#endif
