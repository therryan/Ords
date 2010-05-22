/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
		//string translate(string word);	// Gets the translation of a given word
		string repr();						// Prints out all definitions in a human-readable way
};

#endif
