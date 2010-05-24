/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "file.h"

void writeData(string filename, string data)
{
	writePlaintext(filename, data);
}

string readData(string filename)
{
	return readPlaintext(filename);
}
