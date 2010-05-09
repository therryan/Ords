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
				
	for (unsigned int i = 0; i < dict.size(); i++)
	{
		vector<string> def = split(dict[i], ";");
		
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
					_dict.push_back(Wrapper(Definition(word[0], word[1])));
				}
			}						
		}				
	}
	
	return true;	// Loading went fine, add to Collection
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
