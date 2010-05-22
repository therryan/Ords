/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef QUESTION_H
#define QUESTION_H

#include "dictionary.h"
#include "wrapper.h"

#include "../utils/utils.h"

class Question 
{
	private:
		string _dictTitle;
		vector<Wrapper> _dict;

		int _elem;	// Points to the current element
		
		bool _reverse;
		string _lang;

	public:
		Question(Dictionary dict);
				
		int size();
		
		void setReverse(bool reverse);
		void setLang(string lang);

		bool containsType(string type);
	 	string ask();		// Returns the question
		string answer();	// Returns the answer

		// Checks if 'guess' is correct, deprecates 'answer()' in many cases,
		// must be used because Definitions have multiple possible answers
		bool verify(string guess, string exclude);
		
		// Removes the previously asked question
		void remove();
};

#endif
