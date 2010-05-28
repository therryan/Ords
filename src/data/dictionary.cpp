/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "dictionary.h"

Dictionary::Dictionary(string title)
{
	_dictTitle = title;
}

Dictionary::Dictionary(Wrapper wrap, string title)
{
	_dict.push_back(wrap);
	_dictTitle = title;
}

string Dictionary::getTitle()
{
	return _dictTitle;
}

vector<Wrapper> Dictionary::getDict()
{
	return _dict;
}

int Dictionary::size()
{
	return _dict.size();
}

bool Dictionary::load(string file)
{	
	string data;
	
	try
	{
		data = readData(Settings::dataPath(file));
	}	
	catch (string error)
	{
		cerr << error << endl;
		return false;
	}
					
	vector<string> dict = split(data, "\n"); // Splits to lines
				
	// Work on every line
	for (unsigned int i = 0; i < dict.size(); i++)
	{
		// We must have this so that we can add to this temporarily and add it later
		Definition *definition = new Definition();
		
		// This thing is here to prevent Defs from getting added if they don't exist
		bool addDef = false;
		vector<string> def = split(dict[i], ";");
		
		// Work on every pair		
		for (unsigned int i = 0; i < def.size(); i++)
		{						
			vector<string> word = split(def[i], ":");
			
			if (word.size() == 2) // Must contain two elements
			{
				// DTs are in the form of X:>Y;
				if (word[1].substr(0, 1) == ">")
				{
					_dict.push_back(Wrapper(DefinitionTerm(word[0], word[1].substr(1))));
				}
				
				// Defs are in the form of X:Y;
				else
				{
					addDef = true;	// Go on and actually add the def the the dict
					definition->add(Word(word[1], word[0]));
				}
			}						
		}
		
		// Only if the def was found
		if (addDef)
		{
			_dict.push_back(Wrapper(*definition));
		}
		
		delete definition;	
	}
	
	return true;	// Loading was successful, add to Collection
}

// Call save() on all wrappers
void Dictionary::save()
{
	string data;
	
	for (unsigned int i = 0; i < _dict.size(); i++)
	{
		data += _dict[i].save();
	}
	
	writeData(Settings::dataPath(_dictTitle), data);
}

void Dictionary::add(Wrapper wrap)
{
	_dict.push_back(wrap);
}

string Dictionary::translate(string word)
{
	for (unsigned int i = 0; _dict.size(); i++)
	{
		if (_dict[i].getTranslation(word).length() > 0)
		{
			cout << "T:" << _dict[i].getTranslation(word) << endl;
			return _dict[i].getTranslation(word);
		}
	}

	return "";
}

// Calls repr() on all wrappers 
string Dictionary::repr()
{
	string data;
		
	for (unsigned int i = 0; i < _dict.size(); i++)
	{
		data += _dict[i].repr();
	}

	return data;
}
