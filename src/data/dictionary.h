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
// 		src/data/dictionary.h -- The Dictionary class
// 	
// A Dictionary contains many Definitions and/or DefinitionTerms
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "../file/file.h"
#include "../utils/utils.h"

#include "definition.h"
#include "def_term.h"
#include "wrapper.h"

class Dictionary
{
	private:
		string _dictTitle;				// The title (filename) of the dict
		vector<Wrapper> _dict;
		
	public:
		Dictionary(string title = "");
		Dictionary(Wrapper wrap, string title = "");	
	
		string getTitle();
		vector<Wrapper> getDict();

		int size();
		
		void load(string file);
		void save();	// Gets called by Collection::save()
		
		void add(Wrapper wrap);

		//void remove(string word);			// Removes one definition
		//string translate(string word);	// Gets the translation of a given word
		string repr();						// Prints out all definitions in a human-readable way
};

#endif
