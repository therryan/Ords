/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef ARGS_PARSER_H
#define ARGS_PARSER_H

#include "../utils/utils.h"

class ArgsParser
{
	private:
		ArgsParser();

		static void setNext();

		static vector<string> _args;
		static string _error;
		static string _flag;
		static string _param;
		
	public:
		static int argsLeft();
		
		static void load(vector<string> args);
		static void load(int argc, char *argv[]);
		
		static string error();
		static string flag();
		static string parameter();
		static void remove();
	
		static string repr();
};

#endif

