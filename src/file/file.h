/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
