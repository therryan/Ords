//	Copyright 2010 Teemu Vasama, licensed under the GNU General Public License version 3
//		See LICENSE for details
//
//		srd/data/question.h - The Question-class
//
//	Used by the 'ask'-command. It directly inherits from the Dictionary-class

#ifndef QUESTION_H
#define QUESTION_H

#include "dictionary.h"
#include "wrapper.h"

#include "../utils/utils.h"

class Dictionary;
class Question 
{
	private:
		string _dictTitle;
		vector<Wrapper> _dict;

		int _elem;	// Points to the current element
		
		bool _reverse;

	public:
		Question(Dictionary dict);
				
		int size();
		
		void setReverse(bool reverse);
		
	 	string ask();		// Returns the question
		string answer();	// Return the answer
		void remove();		// Removes the previously asked question
};

#endif
