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
// 		src/data/collection.h -- The Collection class
// 	
// The Collection is on the top of the hierarchy, as it contains
//		all the Dictionaries
// Collection is a global singleton

#ifndef COLLECTION_H
#define COLLECTION_H 

#include "../utils/using.h"

#include "data.h"

class Dictionary; // Really? I guess so...
class Question;

class Collection
{
	private:
		Collection();
		
		static vector<Dictionary> _collection;
		static int _currentDict;
		
	public:
		static bool init();
		
		static void setCurrentDict(string title); // Selects the dict to use

		// A low-level function; passes the dicts by reference
		/*static void getDict(vector<Definition> &defDict,
							vector<DefinitionTerm> &dtDict);*/

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
