/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
