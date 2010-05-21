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

#include "args.h"

// The same arguments the main() has
bool parseArgs(int argc, char *argv[])
{
	//using namespace std;
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
		{
			args::help();
		}
		
		else if ((args[0] == "-r" ||
		 		  args[0] == "--read") && args.size() > 1)
		{
			args::read(args[1]);
		}
		
		else if (args[0] == "-a" ||
				 args[0] == "--add")
		{
			//args::add();
		}
		
		else if (args[0] == "-v" ||
				 args[0] == "--version")
		{
			args::version();
		}

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
	//void add(string content)
	void help()
	{	
		
	}
	void read(string target)
	{
		try
		{
			readData(target);
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
