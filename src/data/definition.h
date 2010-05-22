/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef DEFINITION_H
#define DEFINITION_H

#include "../utils/utils.h"

#include "def_term.h"

class Word
{
	private:
		string _lang;
		string _word;
		
	public:
		Word(string word);
		Word(string word, string lang);
		
		string getWord();
		string getLang();
		
		void setWord();
		void setLang();
};

class Definition
{
	private:
		vector<Word> _translations;
		
	public:
		Definition();
		Definition(DefinitionTerm dt);		// For creating a def from a dt
		Definition(Word word);				// For creating a def from a Word
				
		string getWordByLanguage(string lang);
		bool isInDefinition(string word, string exclude);

		string save();	// When Collection::save() is called, this will eventually get called
		void add(Word word);
		string repr();	// Returns the smart representation of the object
};

#endif
