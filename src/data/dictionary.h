/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "../utils/utils.h"

#include "../file/file.h"
#include "../file/settings.h"
#include "wrapper.h"

class Dictionary
{
	private:
		string _dictTitle;	// The title (filename) of the dict
		vector<Wrapper> _dict;
		
	public:
		Dictionary(string title = "");
		Dictionary(Wrapper wrap, string title = "");	
	
		string getTitle();
		vector<Wrapper> getDict();

		int size();
		
		bool load(string file);	// Returns true if loading was succesful
		void save();	// Gets called by Collection::save()
		
		void add(Wrapper wrap);

		//void remove(string word);			// Removes one definition
		string translate(string word);		// Gets the translation of a given word
		string repr();						// Prints out all definitions in a human-readable way
};

#endif
