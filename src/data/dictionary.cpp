/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
		vector<string> def = split(dict[i], ";");
		
		// Work on every pair		
		for (unsigned int i = 0; i < def.size(); i++)
		{						
			vector<string> word = split(def[i], ":");
			
			if (word.size() == 2) // Must contain two elements
			{
				// DTs are in the form of X:>Z;
				if (word[1].substr(0, 1) == ">")
				{
					_dict.push_back(Wrapper(DefinitionTerm(word[0], word[1].substr(1))));
				}
				
				// Defs are in the form of X:Y;
				else
				{
					definition->add(Word(word[1], word[0]));
				}
			}						
		}
		
		_dict.push_back(Wrapper(*definition));
		
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
