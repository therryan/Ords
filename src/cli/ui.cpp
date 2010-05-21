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

#include "ui.h"

void startUI()
{
	string input;
		
	do
	{
		input = prompt();
	} while (parse(input));
}

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
		if (tokens[0] == "exit") 		{return false;}	// Fall back to main()
		else if (tokens[0] == "def" ||
			   	 tokens[0] == "define")	{ui::define();}
		
		else if (tokens[0] == "ls" ||
				 tokens[0] == "list")	{ui::list();}
			
		else if (tokens[0] == "lsd")	{ui::listDicts();}
		else if (tokens[0] == "new")	{ui::newDict();}
		else if (tokens[0] == "use")	{ui::use();}
		else if (tokens[0] == "open")	{ui::open();}
		else if (tokens[0] == "help")	{ui::help();}
		
		// The first argument 'language' must be zero-length
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
		if (tokens[0] == "list" || tokens[0] == "ls")
		{
			if (tokens[1] == "-d")	{ui::listDicts();}
			else					{ui::listFile(tokens[1]);}
		}
		else if (tokens[0] == "new")	{ui::newDict(tokens[1]);}
		else if (tokens[0] == "use")	{ui::use(tokens[1]);}
		else if (tokens[0] == "open")	{ui::open(tokens[1]);}
		
		else if (tokens[0] == "def" ||
				 tokens[0] == "define")	{ui::define(tokens[1]);}

		// Don't ask in reverse, mainly because it doesn't make any sense with Defintions
		else if (tokens[0] == "ask")	{ui::ask(tokens[1], false);}

		else
		{
			cout << "Command '" << tokens[0] << "' doesn't exist. " <<
				"Type 'help' to see all the commands." << endl;
		}
	}
	return true;
}
