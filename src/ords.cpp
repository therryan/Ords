/* Copyright 2010 Teemu Vasama. Ords is distributed under the GPLv3.
 *
 * This file is part of Ords.
 *
 *   Ords is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 3
 *   as published by the Free Software Foundation.
 *
 *   Ords is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License 
 *	 (the LICENSE file) along with Ords.
 *	 If not, see <http://www.gnu.org/licenses/>.
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
