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
		
		int size();
		
		void load(string file);
		void save();	// Gets called by Collection::save()
		
		void add(Wrapper wrap);

		//void remove(string word);			// Removes one definition
		//string translate(string word);	// Gets the translation of a given word
		string repr();						// Prints out all definitions in a human-readable way
};

#endif
