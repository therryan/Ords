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
		// Initialize the ArgumentParser
		ArgsParser::load(argc, argv);
		
		// As long as there are some args left
		while (ArgsParser::argsLeft() != 0)
		{
		
			if 		(ArgsParser::flag() == "a" ||
					 ArgsParser::flag() == "add")
					{
						if (ArgsParser::parameter().empty())
						{
							cout << "To which dictionary do you want to add?" << endl;
							string target;
							getline(cin, target);
						
							Collection::load(target);
						}
						else
						{
							Collection::load(ArgsParser::parameter());
						}
						
						args::add();	
					}
					
			else if (ArgsParser::flag() == "q" ||
					 ArgsParser::flag() == "ask" ||
					 ArgsParser::flag() == "question")
					{
						if (!ArgsParser::parameter().empty())
						{
							Collection::load(ArgsParser::parameter());
							args::ask("", false);
						}
					}
					
			else if (ArgsParser::flag() == "rask")		{args::ask("", true);}
					
			else if (ArgsParser::flag() == "c" ||
			         ArgsParser::flag() == "config")	{args::config();}
					
			else if (ArgsParser::flag() == "h" ||
			 	     ArgsParser::flag() == "help")		{args::help();}
			
			else if (ArgsParser::flag() == "i" ||
					 ArgsParser::flag() == "info")		{args::info();}
			
			else if (ArgsParser::flag() == "n" ||
					 ArgsParser::flag() == "new")		{args::newDict(ArgsParser::parameter());}
		
			else if (ArgsParser::flag() == "r" || 
					 ArgsParser::flag() == "read")
					{
						if (ArgsParser::parameter().size() > 0)
						{
							args::read(ArgsParser::parameter());
						}
						else // If the user didn't give a param, ask for it
						{							
							cout << "Please enter the name of the file " <<
							"you wish to open:" << endl;
								
							string filename;
							getline(cin, filename);
							
							if (!filename.empty())
							{							
								args::read(filename);
							}
						}
					}

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
	void add()
	{
		ui::define();
	}
	
	void ask(string lang, bool reverse)
	{
		ui::ask(lang, reverse);
	}
	
	void config()
	{
		ui::config();
	}
	
	void help()
	{	
		cout << "-a, --add" << "\n" 
				<< "\tDefine a new word or term\n"
		
			 << "-q, --question, --ask [file]" << "\n"
			 	<< "\tAsks all the contents of 'file'\n"
			 
			 << "-c, --config" << "\n"
			 	<< "\tAllows you to change the settings without having to modify the config file\n"

			 << "--rask" << "\n" 
			 	<< "\tAsks in reverse order\n"
							
			 << "-h, --help" << "\n"
			 	<< "\tDisplays this message\n"
			
			 << "-i, --info" << "\n"
			 	<< "\tDisplays information like the version number etc.\n"
			
			 << "-r, --read [file]" << "\n"
			 	<< "\tLists all definitions in 'file'\n"
						
			 << "-n, --new [title]" << "\n"
			 	<< "\tOpens a new dictionary with 'title' as the title. "
				<< "If no arguments are given, ask for the title\n"
								 
			 << endl;
	}
	
	void info()
	{
		cout << "ords version:" << Settings::version() << endl;
		cout << "modified last on: " << Settings::versionInfo() << endl;
	}
	
	void newDict(string dict)
	{
		ui::newDict(dict);
	}
	
	void read(string file)
	{
		ui::listFile(file);
	}
}
