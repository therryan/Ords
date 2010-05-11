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

// 
// 		src/data/definition.h -- The Definition class (and the Word class)
// 	
// A Word is the smallest unit in the hiearachy,
// one word + language
//
// A Definition is a collection of Words

#ifndef DEFINITION_H
#define DEFINITION_H

#include "def_term.h"

#include "../utils/utils.h"

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
		
		// To be deprecated?? One can just do foo(Word(word, lang))?
		Definition(string word, string lang);
		
		bool isInDefinition(string word);

		string save();	// When Collection::save() is called, this will eventually get called
		
		void add(Word word);
		void add(string word, string lang); // Also to be deprecated (see above)??
		
		string repr();	// Returns the smart representation of the object
};

#endif
