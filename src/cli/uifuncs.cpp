#include "uifuncs.h"

namespace ui
{
	void ask()
	{
		srand(time(NULL));
		
		Question quest = Collection::getQuestion();
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

			if (answer == quest.answer())
			{
				cout << "Correct!" << endl << endl;
				quest.remove();
			}
			else
			{
				cout << "Incorrect!" << endl << endl;
			}
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
		int which;
		
		if (choice.length() == 0)
		{
			cout << "Would you like to define a dt (0) or a def (1) ? ";
			which = getInt();
		}
		
		if (which == 0 || choice == "dt" || choice == "term")
		{
			bool again = true;
			while (again == true)
			{
				DefinitionTerm dt;
				again = defDt(dt);
				Collection::add(dt);
			}
		}
		else if (which == 1 || choice == "def" || choice == "definition" ||
				choice == "word")
		{
			bool again = true;
			while (again == true)
			{
				Definition def;
				again = defDefinition(def);
				Collection::add(def);
			}
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	
	bool defDefinition(Definition &def)
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
		
		return true;
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
		
		cout << "Definitions of words:\n"
			 << defs.str() << endl << endl << "Definitions of terms:\n"
		 	 << dts.str() << endl;
	}
	
	void help()
	{
		
	}
}

