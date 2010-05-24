/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef ARGS_H
#define ARGS_H 

#include <fstream>

#include "../utils/utils.h"

#include "../file/file.h"
#include "../file/settings.h"
#include "args_parser.h"

// If should continue, return true
bool parseArgs(int argc, char *argv[]);

// A namespace that contains all the functions that take care of a certain switch
namespace args 
{
	void add(string content);
	void ask(string lang, bool reverse);
	void config();
	void help();
	void newDict();
	void read(string target);
	void version();
}

#endif
