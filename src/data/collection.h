/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef COLLECTION_H
#define COLLECTION_H 

#include "../utils/using.h"

#include "definition.h"
#include "def_term.h"
#include "dictionary.h"
#include "question.h"

class Collection
{
	private:
		Collection();
		
		static vector<Dictionary> _collection;
		static int _currentDict;
		
	public:
		static bool init();
		
		static void setCurrentDict(string title); // Selects the dict to use
		
		static Question getQuestion();	// Return a Question-object based on the _currentDict	
		static int size();	// Return the amount of dictionaries loaded
		
		static void load(string file);
		static bool save();
				
		static void add(Dictionary dict);
		static void add(Definition def);	// Add to current dict
		static void add(DefinitionTerm dt);	// -''-

		static void remove();				// Based on same kind of a unique id?
		static string dictionaries();		// Returns names of all dictionaries
		static string definitions();		// Calls repr() on all dictionaries
};

#endif
