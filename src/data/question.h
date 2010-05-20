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
		string _lang;

	public:
		Question(Dictionary dict);
				
		int size();
		
		void setReverse(bool reverse);
		void setLang(string lang);

		bool containsType(string type);
	 	string ask();		// Returns the question
		string answer();	// Returns the answer

		// Checks if 'guess' is correct, deprecates 'answer()',
		// must be used because Definitions have multiple possible answers
		bool verify(string guess, string exclude);
		
		// Removes the previously asked question
		void remove();
};

#endif
