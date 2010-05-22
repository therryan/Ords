/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <fstream>

#include "../utils/using.h"

using std::ifstream;
using std::ofstream;
using std::ios;

void writePlaintext(string filename, string data);
string readPlaintext(string filename);

#endif
