/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "utils/utils.h"
#include "file/file.h"
#include "init/init.h"
#include "cli/args.h"
#include "cli/ui.h"

#ifdef WITH_GUI
#	include "qt/qt_main.h"
#endif

int main(int argc, char *argv[])
{		
    if (init()) {}	// Init worked, moving on
	else 			// Otherwise, stop the program
	{
		cerr << "Init failed" << endl;
		exit(EXIT_FAILURE);
	}
	
	// If was compiled with the flag WITH_GUI, the QT stuff is included
	#ifdef WITH_GUI
		return QtMain(argc, argv);
	#endif
			
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