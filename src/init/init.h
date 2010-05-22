/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef INIT_H
#define INIT_H 

#include "../utils/utils.h"

#include "../data/collection.h"
#include "../file/settings.h"

// Initializes the program, returns true if everything went fine
bool init();

// Deinitializes the program, also return true if all is OK
bool deinit();		

#endif
