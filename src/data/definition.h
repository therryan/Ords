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
		
		string save();	// When Collection::save() is called, this will eventually get called
		
		void add(Word word);
		void add(string word, string lang); // Also to be deprecated (see above)??
		
		string repr();	// Returns the smart representation of the object
};

#endif