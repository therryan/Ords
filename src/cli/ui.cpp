/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "ui.h"

void startUI()
{
	string input;
	
	// The do-it-all loop, the magic happens here
	do
	{
		input = prompt();
	} while (parse(input));
}

// By default 'prompt' is ">>> "
string prompt(string prompt)
{
	cout << prompt;
	string input;
	getline(cin, input);
	
	return input;
}

// Matches the user input with the correct functions
bool parse(string input)
{
	if (input.length() == 0)
	{
		return true;
	}
	
	vector<string> tokens = split(input, " ");
	
	if (tokens.size() == 1)
	{	
		if 		(tokens[0] == "exit") 	{return false;}	// Fall back to main()
		
		else if (tokens[0] == "config")	{ui::config();}
		
		else if (tokens[0] == "def" ||
			   	 tokens[0] == "define")	{ui::define();}
			
		else if (tokens[0] == "help")	{ui::help();}
		
		else if (tokens[0] == "ls" ||
				 tokens[0] == "list")	{ui::list();}
				
		else if (tokens[0] == "lsd")	{ui::listDicts();}
		else if (tokens[0] == "new")	{ui::newDict();}
		else if (tokens[0] == "open")	{ui::open();}
		else if (tokens[0] == "use")	{ui::use();}
		
		// The first argument 'language' must be zero-length
		// because no language was given
		else if (tokens[0] == "rask")	{ui::ask("", true);}	// To reverse
		else if (tokens[0] == "ask")	{ui::ask("", false);}	// or not
		
		else
		{
			cout << "Command '" << tokens[0] << "' doesn't exist. Type help " <<
				"to see all the commands." << endl;
		}
	}
	else if (tokens.size() > 1) // Cmds that have arguments (e.g. 'open test')
	{
		// Don't ask in reverse, mainly because it doesn't make any sense with Defintions
		if 		(tokens[0] == "ask")	{ui::ask(tokens[1], false);}
		
		else if (tokens[0] == "def" ||
				 tokens[0] == "define")	{ui::define(tokens[1]);}
				
		else if (tokens[0] == "list" || tokens[0] == "ls")
		{
			if (tokens[1] == "-d")		{ui::listDicts();}
			else						{ui::listFile(tokens[1]);}
		}
		else if (tokens[0] == "new")	{ui::newDict(tokens[1]);}
		else if (tokens[0] == "open")	{ui::open(tokens[1]);}
		else if (tokens[0] == "use")	{ui::use(tokens[1]);}
		
		else
		{
			cout << "Command '" << tokens[0] << "' doesn't exist. " <<
				"Type 'help' to see all the commands." << endl;
		}
	}
	
	return true;
}
