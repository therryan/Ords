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
		
		else if (tokens[0] == "rask")	{ui::ask(true);}	// To reverse
		else if (tokens[0] == "ask")	{ui::ask(false);}	// or not
		
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
		else
		{
			cout << "Command '" << tokens[0] << "' doesn't exist. Type help " <<
				"to see all commands." << endl;
		}
	}
	return true;
}
