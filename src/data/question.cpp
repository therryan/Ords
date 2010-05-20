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

#include "question.h"

Question::Question(Dictionary dict)
{
	_dictTitle = dict.getTitle();
	_dict = dict.getDict();	
	_reverse = false;
	_lang = " ";
}

int Question::size()
{
	return _dict.size();
}

void Question::setReverse(bool reverse)
{
	_reverse = reverse;
}

void Question::setLang(string lang)
{
	_lang = lang;
}

bool Question::containsType(string type)
{
	if (type != "Definition" && type != "DefinitionTerm" && type != "Conjugation")
	{
		throw "Type'" + type + "' doesn't exist.";
	}
	
	for (unsigned int i = 0; i < _dict.size(); i++)
	{
		if (_dict[i].type () == type)
		{
			return true;
		}
	}
	
	return false;
}

string Question::ask()
{
	if (_dict.size() > 0)
	{
		_elem = getRand(_dict.size());
		
		string type = _dict[_elem].type();
				
		if (type == "Definition" && _lang.length() > 0)
		{
			return _dict[_elem].getWord(_lang);
		}
		
		if (type == "DefinitionTerm")
		{
			if (_reverse == true)
			{
				return _dict[_elem].getDescr();
			}
			else
			{
				return _dict[_elem].getTerm();
			}
		}
	}

	return false;
}

string Question::answer()
{
	if (_dict.size() > 0 && _dict[_elem].type() == "DefinitionTerm")
	{
		if (_reverse == true)
		{
			return _dict[_elem].getTerm();
		}

		return _dict[_elem].getDescr(); 
	}

	if (_dict.size() > 0 && _dict[_elem].type() == "Definition")
	{
		//return _dict[_elem].getWord(_lang);
		return "MULTIPLE ANSWERS AVAILABE";
	}

	return "";
}

// Exclude is just the asked form of Definitions, we don't
// want the user using that
bool Question::verify(string guess, string exclude)
{
	if (_dict.size() > 0)
	{
		string type = _dict[_elem].type();
		
		if (type == "DefinitionTerm")
		{
			if (_reverse == true)
			{
				if (_dict[_elem].getTerm() == guess)
				{
					return true;
				}
			}
			else
			{
				if (_dict[_elem].getDescr() == guess)
				{
					return true;
				}
			}
		}

		if (type == "Definition")
		{
			if (_dict[_elem].includes(guess, exclude))
			{
				return true;
			}
		}
	}
	
	return false;
}

void Question::remove()
{
	if (_dict.size() > 0)
	{
		_dict.erase(_dict.begin() + _elem);
	}
}
