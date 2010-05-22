/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef FILE_H
#define FILE_H

#include "../utils/utils.h"

#include "plaintext.h"

/* The following functions are dummies that just call the real functions, 
 * implemented for the distant possibility of doing a MySQL-interface. For now, 
 * they don't really do anything */

void writeData(string filename, string data);
string readData(string filename);

#endif
