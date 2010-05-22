/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#include "utils/utils.h"

#include "file/file.h"
#include "init/init.h"

#include "cli/args.h"
#include "cli/ui.h"

int main(int argc, char *argv[])
{		
    if (init()) {}	// Init worked, moving on
	else 			// Otherwise, stop the program
	{
		cerr << "Init failed" << endl;
		exit(EXIT_FAILURE);
	}
			
	// If there are some arguments, parse them and skip the interactive mode
	if (!parseArgs(argc, argv))	{}
	
	// If there were no arguments, start the interactive mode
	else {startUI();}
	
	// Deinit worked, closing down...
	if (deinit())
		{return EXIT_SUCCESS;}
		
	else
	{
		cerr << "DEINIT failed!\n";
		exit(EXIT_FAILURE);
	}
}
