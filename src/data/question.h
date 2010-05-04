//	Copyright 2010 Teemu Vasama, licensed under the GNU General Public License version 3
//		See LICENSE for details
//
//		srd/data/question.h - The Question-class
//
//	Used by the 'ask'-command. It directly inherits from the Dictionary-class

#ifndef QUESTION_H
#define QUESTION_H

#include "dictionary.h"
#include "definition.h"
#include "def_term.h"

#include "../utils/utils.h"

class Question 
{
	private:
		string _dictTitle;
		vector<Definition> _defDict;
		vector<DefinitionTerm> _dtDict;

		int _defElem;	// Points to the current Def-element
		int _dtElem;	// Points to the current DT-element

	public:
		Question(Dictionary dict);
		
		int size();
	 	string ask();		// Returns the question
		string answer();	// Return the answer
		void remove();		// Removes the previously asked question
};

#endif
