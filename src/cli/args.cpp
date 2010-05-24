/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "args.h"

bool parseArgs(int argc, char *argv[])
{	
	if (argc == 1)	   // argv[0] is always the name of the program, the size is always > 0
		{return true;} // If no arguments are given, go to interavtive mode
		
	else if (argc > 1)
	{
		// Initialize the ArguentParser
		ArgsParser::load(argc, argv);
		
		// As long as there are some args left
		while (ArgsParser::argsLeft() != 0)
		{
		
			if      (ArgsParser::flag() == "h" ||
			 	     ArgsParser::flag() == "help")
					{args::help();}
		
			else if (ArgsParser::flag() == "r" || 
					 ArgsParser::flag() == "read")
					{
						if (ArgsParser::parameter().size() > 0)
						{
							args::read(ArgsParser::parameter());
						}
						else // If the user didn't give a param, ask for it
						{
							string filename;
							
							cout << "Please enter the name of the file " <<
							"you wish to open:" << endl;
								
							getline(cin, filename);
							
							if (!filename.empty())
							{							
								args::read(filename);
							}
						}
					}
		
			else if (ArgsParser::flag() == "a" ||
					 ArgsParser::flag() == "add")
					{/*args::add();*/}
		
			else if (ArgsParser::flag() == "v" ||
					 ArgsParser::flag() == "version")
					{args::version();}

			// If an argument is unknown, inform the user about it
			else 
			{
				cout << "Unknown argument '" + ArgsParser::error() + "'" << endl;
			}
			
			// Remove the flag (and param, if any) that were used previously
			ArgsParser::remove();
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
	
	void config()
	{
		
	}
	
	void help()
	{	
		cout << "Available commands:\n\n"
		
			 << endl;
	}
	
	void newDict()
	{
		
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
