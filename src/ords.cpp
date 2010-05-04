/* ords.cpp - the main file
 *		Copyright Teemu Vasama 2010
 *		Licensed under the GPLv3
 */

#include "file/file.h"
#include "cli/cli.h"
#include "data/data.h"
#include "init/init.h"
#include "utils/utils.h"

int main(int argc, char *argv[])
{		
    if (init()) {}	// Init worked, moving on
	else 			// Otherwise, stop the program
	{
		cerr << "Init failed";
		exit(EXIT_FAILURE);
	}
			
	// If there are some arguments, parse them and skip the interactive mode
	if (!parseArgs(argc, argv))	{}
	
	// If there are no arguments, start the interactive mode
	else {startUI();}
	
	if (deinit()) 	// Deinit worked, closing down...
	{
		return EXIT_SUCCESS;
	}
	else
	{
		cerr << "DEINIT failed!\n";
		exit(EXIT_FAILURE);
	}
}
