/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
