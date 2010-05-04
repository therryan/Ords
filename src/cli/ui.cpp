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
		if (tokens[0] == "exit") 	{return false;}	// Fall back to main()
		if (tokens[0] == "def" ||
			tokens[0] == "define")	{ui::define();}
		
		if (tokens[0] == "ls" ||
			tokens[0] == "list")	{ui::list();}
			
		if (tokens[0] == "lsd")		{ui::listDicts();}
		if (tokens[0] == "new")		{ui::newDict();}
		if (tokens[0] == "use")		{ui::use();}
		if (tokens[0] == "open")	{ui::open();}
		if (tokens[0] == "ask")		{ui::ask();}
	}
	else if (tokens.size() > 1)
	{
		if (tokens[0] == "list")
		{
			if (tokens[1] == "-d")	{ui::listDicts();}
			else					{ui::listFile(tokens[1]);}
		}
		if (tokens[0] == "new")		{ui::newDict(tokens[1]);}
		if (tokens[0] == "use")		{ui::use(tokens[1]);}
		if (tokens[0] == "open")	{ui::open(tokens[1]);}
		if (tokens[0] == "def" ||
			tokens[0] == "define")	{ui::define(tokens[1]);}
	}
	return true;
}

