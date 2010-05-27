/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
		
		string repr();
};

#endif
