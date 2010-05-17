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

#include "uifuncs.h"

namespace ui
{
	void ask(bool reverse)
	{
		srand(time(NULL));
		
		Question quest = Collection::getQuestion();
		
		if (reverse == true)
		{
			quest.setReverse(true);
		}
		
		int origSize = quest.size();

		if (quest.size() == 0)
		{
			cout << "The dictionary is empty!" << endl;
		}

		while (quest.size() > 0)
		{
			cout << quest.size() << "/" << origSize << " left!" << endl;
			cout << quest.ask() << endl;	
			
			string answer;
			getline(cin, answer);

			if (quest.verify(answer))
			{
				cout << "Correct!" << endl;
				quest.remove();
			}
			else
			{
				cout << "Incorrect!" << endl
				 	 << "The correct answer was '" + quest.answer() + "'. "
				     << "Were you correct? (y/n)" << endl;
				
				string ans;
				getline(cin, ans);
				
				if (ans == "y")
				{
					quest.remove();
				}
			}
			
			cout << endl;
		}
	}
	
	void open(string file)
	{
		if (file.length() == 0)
		{
			cout << "Which file to open? ";
			getline(cin, file);
		}
		
		Collection::load(file);
	}
	
	void newDict(string title)
	{
		if (title.length() == 0)
		{
			cout << "Title for the new dictionary: ";
			getline(cin, title);
		}
		
		Collection::add(Dictionary(title));
	}
	
	void use(string title)
	{
		if (Collection::size() > 0)
		{
			if (title.length() == 0)
			{
				cout << "Which dictionary to use?: ";
				getline(cin, title);
			}
		
			Collection::setCurrentDict(title);
		}
		else
		{
			cout << "There are no dictionaries!" << endl;
		}
	}
	
	void define(string choice)
	{
		if (Collection::size() == 0)
		{
			cout << "There are no dictionaries present, " << 
				"please create one!" << endl << endl;
			newDict();
		}
		
		int which;
		
		if (choice.length() == 0)
		{
			cout << "Would you like to define a term (0) or a word (1) ? ";
			which = getInt();
		}
		
		if (which == 0 || choice == "dt" || choice == "term")
		{
			bool again = true;
			while (again == true)
			{
				DefinitionTerm dt;
				again = defDt(dt);
				
				if (again == true)
				{
					Collection::add(dt);
				}
			}
		}
		else if (which == 1 || choice == "def" || choice == "definition" ||
				choice == "word")
		{
			Definition def;
			defDefinition(def);
			Collection::add(def);
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	
	void defDefinition(Definition &def)
	{
		string word, lang;
		
		while (true)
		{		
			cout << "Enter a word: ";
			getline(cin, word);
			
			if (word.length() == 0)
			{
				break;
			}
		
			cout << "Enter the language: ";
			getline(cin, lang);
			
			if (lang.length() == 0)
			{
				def.add(word);
			}
			else
			{
				def.add(word, lang);
			}
		}
	    cout << def.repr();
	}
	
	bool defDt(DefinitionTerm &dt)
	{
		string term, descr;
		
		cout << "Enter the term" << endl;
		getline(cin, term);
		
		if (term.length() == 0)
		{
			return false;
		}
		
		cout << "Enter the description" << endl;
		getline(cin, descr);
	
		dt.setTerm(term);
		dt.setDescr(descr);
		
		cout << dt.repr();
		
		return true;
	}
	
	void list()
	{
		cout << Collection::definitions();
	}
	
	void listDicts()
	{
		cout << Collection::dictionaries();
	}
	
	void listFile(string file)
	{
		stringstream defs, dts;
		
		try
		{
			string data = readData(Settings::dataPath(file));
									
			vector<string> dict = split(data, "\n");
			cout << endl;
						
			for (unsigned int i = 0; i < dict.size(); i++)
			{
				vector<string> def = split(dict[i], ";");
				
				for (unsigned int i = 0; i < def.size(); i++)
				{						
					vector<string> word = split(def[i], ":");
					
					if (word.size() == 2) // Must contain two elements
					{
						if (word[1].substr(0, 1) == ">")
						{
							DefinitionTerm* dt = new DefinitionTerm(word[0], word[1].substr(1));
							dts << dt->repr();
							delete dt;
						}
						
						else
						{
							defs << word[0] + ":   " << setw(5) << word[1] << endl;
						}
					}						
				}				
			}
		}	
		catch (string error)
		{
			cout << error << endl;
		}
		
		cout << defs.str() << endl << dts.str() << endl;
	}
	
	void help()
	{
		cout << "\t" << "ask" << "\n"
			 	<< "\t\tAsks all the definitions in the current dictionary\n"
			
			 << "\t" << "rask" << "\n" 
			 	<< "\t\tAsks Y->X instead of X->Y\n"
			
			 << "\t" << "def, define [word|term]" << "\n" 
				<< "\t\tDefine a new word or term. If no argument given, go\n"
				<< "\t\tto continuous input mode\n"
				
			 << "\t" << "exit" << "\n"
			 	<< "\t\tQuits the program, saving all files\n"
			
			 << "\t" << "help" << "\n"
			 	<< "\t\tDisplays this message\n"
			
			 << "\t" << "list, ls [file]" << "\n"
			 	<< "\t\tLists all definitions in the current dictionary.\n"
				<< "\t\tIf the argument is given, list all the definitions\n"
				<< "\t\tin that file\n"
			
			 << "\t" << "lsd|ls -d" << "\n"
			 	<< "\t\tList dictionaries\n"
			
			 << "\t" << "new [title]" << "\n"
			 	<< "\t\tOpens a new dictionary with the argument as the title.\n"
				<< "\t\tIf no arguments are given, ask for the title\n"
			
			 << "\t" << "open [file]" << "\n"
			 	<< "\t\tTries to open the file specified as the argument.\n"
				<< "\t\tIf no argument is given, ask for the file to open\n"
			
			 << "\t" << "use [dictionary]" << "\n"
			 	<< "\t\tSwitch the dictionary to 'dictionary'.\n"
				<< "\t\tIf no argument is given, ask for the dictionary\n"
			 
			 << endl;
	}
}
