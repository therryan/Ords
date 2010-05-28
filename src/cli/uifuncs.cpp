/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "uifuncs.h"

namespace ui
{
	void ask(string lang, bool reverse)
	{
		srand(time(NULL));

		if (Collection::size() == 0)
		{
			cout << "There are no dictionaries, please open one: ";
			string filename;
			getline(cin, filename);
			
			Collection::load(filename);
		}
		
		// Get a Question-object from the current dictionary
		Question quest = Collection::getQuestion();
		//cout << quest.repr();
		
		// When 'rask' was used
		if (reverse == true)
		{
			quest.setReverse(true);
		}
		
		// If the language was given i.e. we have defs coming
		if (lang.length() > 0)
		{
			quest.setLang(lang);
		}

		// If we weren't given a language but there still are defs
		else
		{
			if (quest.containsType("Definition"))
			{
				cout << "Enter the language you want the questions to be from" << endl;
				string language;
				getline(cin, language);
				
				if (language.length() > 0)
				{
					quest.setLang(language);
				}
			}
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
			
			// The second argument is 'exclude', so that when we are asking questions
			// based on defs, we don't want the question to also be the answer
			if (quest.verify(answer, quest.answer()))
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
	
	void translate(string word)
	{
		if (word.empty())
		{
			cout << "Which word do you want to translate?" << endl;
			string tmp;
			getline(cin, tmp);
			word = tmp;
		}

		if (Collection::size() == 0)
		{
			cout << "Please open a dictionary" << endl;
			open();
		}

		cout << "Translation for '" << word << "' is: " << endl
			 << "\t" << Collection::translate(word) << endl;
	}

	void use(string title)
	{
		// We don't want to try use a dict if there are none
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
		// If there are no dicts, where would our defs go? :(
		// So that's why we're creating a new dict here
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

				// defDt() return false if the user doesn't want to continue
				// And the argument is passed by reference, so the Sun shines
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
				// Add it without the language
				def.add(Word(word));
			}
			else
			{
				def.add(Word(word, lang));
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
							// Some more or less black magic going on here to get it look pretty
							defs << word[0] + ":   " << setw(5) << word[1] << endl;
						}
					}						
				}				
			}
		}	
		// Catching readData()'s 'file doesn't exist'-error
		catch (string error)
		{
			cout << error << endl;
		}
		
		cout << defs.str() << endl << dts.str() << endl;
	}

	void config()
	{
		cout << "What do you want to change?" << endl;
		cout << "(1) datapath" << endl;
		
		int ans = getInt();
		
		if (ans == 1)
		{
			cout << "Current value: " << Settings::dataPath() << endl;
			cout << "New value ?: ";
			string datapath;
			getline(cin, datapath);

			Settings::setDirective("datapath", datapath);
		}
	}

	void help()
	{
		cout << "ask" << "\n"
			 	<< "\tAsks all the definitions in the current dictionary\n"
			 
			 << "config" << "\n"
			 	<< "\tAllows you to change the settings without having to modify the config file\n"

			 << "rask" << "\n" 
			 	<< "\tAsks Y->X instead of X->Y\n"
			
			 << "def, define [word|term]" << "\n" 
				<< "\tDefine a new word or term. If no argument given, go\n"
				<< "\tto continuous input mode\n"
				
			 << "exit" << "\n"
			 	<< "\tQuits the program, saving all files\n"
			
			 << "help" << "\n"
			 	<< "\tDisplays this message\n"
			
			 << "list, ls [file]" << "\n"
			 	<< "\tLists all definitions in the current dictionary.\n"
				<< "\tIf the argument is given, list all the definitions\n"
				<< "\tin that file\n"
			
			 << "lsd|ls -d" << "\n"
			 	<< "\tList dictionaries\n"
			
			 << "new [title]" << "\n"
			 	<< "\tOpens a new dictionary with the argument as the title.\n"
				<< "\tIf no arguments are given, ask for the title\n"
			
			 << "open [file]" << "\n"
			 	<< "\tTries to open the file specified as the argument.\n"
				<< "\tIf no argument is given, ask for the file to open\n"
			
			 << "use [dictionary]" << "\n"
			 	<< "\tSwitch the dictionary to 'dictionary'.\n"
				<< "\tIf no argument is given, ask for the dictionary\n"
			 
			 << endl;
	}
}
