/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
		
		string get();

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
