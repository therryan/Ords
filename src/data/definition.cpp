/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#include "definition.h"

Word::Word(string word)
{
	_word = word;
	_lang = "DEFAULT"; // If lang isn't given, then set to default
}

Word::Word(string word, string lang)
{
	_word = word;
	_lang = lang;
}

string Word::getWord()
{
	return _word;
}
string Word::getLang()
{
	return _lang;
}

/* --- Definition --------------------------------------------------------- */

Definition::Definition() {}

Definition::Definition(Word word)
{
	_translations.push_back(word);
}

Definition::Definition(DefinitionTerm dt)
{
	_translations.push_back(Word(dt.getTerm(), dt.getDescr()));
}

string Definition::getWordByLanguage(string lang)
{
	for (unsigned int i = 0; i < _translations.size(); i++)
	{		
		if (_translations[i].getLang() == lang)
		{
			return _translations[i].getWord();
		}
	}

	return "";
}

bool Definition::isInDefinition(string word, string exclude)
{
	for (unsigned int i = 0; i < _translations.size(); i++)
	{
		if (word == _translations[i].getWord() && word != exclude)
		{
			return true;
		}
	}

	return false;
}

string Definition::save()
{
	string data;
	
	for (unsigned int i = 0; i < _translations.size(); i++)
	{
		data += _translations[i].getLang() + ":" +
		 		_translations[i].getWord() + ";";
	}
	data += "\n";
		
	return data;
}

void Definition::add(Word word)
{
	_translations.push_back(word);
}

string Definition::repr()
{
	string repr = "\n";
	
	for (unsigned int i = 0; i < _translations.size(); i++)
	{
		repr += _translations[i].getLang() + ": \t";
		repr += _translations[i].getWord() + "\n";
	}
	
	return repr + "\n";
}
