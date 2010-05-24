/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
