/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#ifndef WRAPPER_H
#define WRAPPER_H

#include "../utils/utils.h"

#include "conjugation.h"
#include "definition.h"
#include "def_term.h"

class Wrapper
{
	private:
		Definition _def;
		DefinitionTerm _dt;
		Conjugation _conj;

		string _type;

	public:
		Wrapper();
		Wrapper(Definition def);
		Wrapper(DefinitionTerm dt);
		Wrapper(Conjugation conj);

	 	/* For DefinitionTerm */
		string getTerm();
		string getDescr();
		
		/* For Definition */
		bool includes(string word, string exclude);
		string getWord(string lang);

		string type();

		string save();
		string repr();
};

#endif
