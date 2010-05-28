/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "collection.h"

// These fields are static so they must be defined outside
vector<Dictionary> Collection::_collection;
int Collection::_currentDict;

// For now this is useless
bool Collection::init()
	{return true;}

// Sets the "pointer" _currentDict to point to the given dict (by title)
void Collection::setCurrentDict(string title)
{
	for (unsigned int i = 0; i < _collection.size(); i++)
	{
		if (_collection[i].getTitle() == title)
		{
			_currentDict = (int)i;
		}
	}
}

Question Collection::getQuestion()
{
	return Question(_collection[_currentDict]);
}

int Collection::size()
{
	return _collection.size();
}

// Loads up a new dict and adds it to the Collection
void Collection::load(string file)
{
	Dictionary dict(file);
	bool success = dict.load(file);
			
	if (success == true)
	{
		_collection.push_back(dict);
	}
}

// Just calls save() on all the dicts, initiating the chain of save()-calls
bool Collection::save()
{
	for (unsigned int i = 0; i < _collection.size(); i++)
	{
		_collection[i].save();
		cout << "Saving '" << _collection[i].getTitle() << "'" << endl;
	}
	
	return true;
}

void Collection::add(Dictionary dict)
{
	_collection.push_back(dict);
}

void Collection::add(Definition def)
{
	// To avoid segfault when def'ing when no dicts are present
	if (_collection.size() > 0)
	{
		_collection[_currentDict].add(def);
	}
}

void Collection::add(DefinitionTerm dt)
{
	// To avoid segfault when def'ing when no dicts are present
	if (_collection.size() > 0) 
	{
		_collection[_currentDict].add(dt);
	}
}

string Collection::translate(string word)
{
	string translation;
	translation = _collection[_currentDict].translate(word);

	return translation;
}

void Collection::remove(/*Some argument here?*/)
{
	
}

// Gets the *names* of all the dictionaries present
// Also shows which dict is the current one
string Collection::dictionaries()
{
	string output;
	
	for (unsigned int i = 0; i < _collection.size(); i++)
	{		
		if (_currentDict == (int)i)
		{
			output += "* " + _collection[i].getTitle() + "\n";
		}
		else
		{
			output += "  " + _collection[i].getTitle() + "\n";
		}
	}
	
	if (_collection.size() > 0)
	{
		return output;
	}
	else // If there are no dictionaries
	{
		return "There are no dictionaries!\n";
	}
}

// Calls repr() on the currently selected dictionary
string Collection::definitions()
{
	if (_collection.size() > 0)
	{
		return _collection[_currentDict].repr();
	}
	else
	{
		return "There are no dictionaries!\n";
	}
}
