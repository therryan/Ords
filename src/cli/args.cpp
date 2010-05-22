/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#include "args.h"

bool parseArgs(int argc, char *argv[])
{
	vector<string> args;
	string programName = argv[0];
	
	if (argc == 1)	   // argv[0] is always the name of the program, the size is always >0
		{return true;} // If no arguments are given, go to interavtive mode
		
	else if (argc > 1)
	{
		// Transitions all the arguments from char** to vector
		for (int i = 1; i < argc; i++) 
		{
			args.push_back(argv[i]);
		}

		if (args[0] == "-h" ||
		 	args[0] == "--help")
				{args::help();}
		
		else if ((args[0] == "-r" || args[0] == "--read") &&
		 		  args.size() > 1)
				{args::read(args[1]);}
		
		else if (args[0] == "-a" ||
				 args[0] == "--add")
				{/*args::add();*/}
		
		else if (args[0] == "-v" ||
				 args[0] == "--version")
				{args::version();}

		// If an argument is unknown, inform the user about it
		else 
		{
			cout << "Unknown argument '" + args[0] + "'" << endl;
			args.erase(args.begin());
		}
	}

	// Don't go to the interactive mode
	return false; 
}

namespace args
{
	void add(string content)
	{
		
	}
	
	void ask(string lang, bool reverse)
	{
		
	}
	
	void help()
	{	
		cout << "";
	}
	
	void read(string file)
	{
		try
		{
			readData(file);
		}
		catch (string error)
		{
			cout << "ERROR: " + error << endl;
		}	
	}
	
	void version()
	{
		cout << "ords version:" << Settings::version() << endl;
		cout << "modified last on: " << Settings::versionInfo() << endl;
	}
}
