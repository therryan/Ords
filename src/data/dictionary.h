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

class Dictionary
{
	private:
		string _dictTitle;				// The title (filename) of the dict
		vector<Definition> _dict;		// One vector for each of the two types
		vector<DefinitionTerm> _dtDict;
		
	public:
		Dictionary(string title = "");
		Dictionary(Definition def, string title = "");
		Dictionary(DefinitionTerm dt, string title = "");
		
		string getTitle();
		vector<Definition> getDefDict();
		vector<DefinitionTerm> getDtDict();
		
		void load(string file);
		void save();	// Collection::save() calls each dict's save() function
		
		void add(Definition def);
		void add(DefinitionTerm dt);
		void add(string word, string translation,
		 		 string langWord = "", string langTranslation = "");	// Deprecation much??
				 
		//void remove(string word);		// Removes one definition
		//string translate(string word);	// Gets the translation of a given word
		string repr();					// Prints out all definitions in a human-readable way
};

#endif
