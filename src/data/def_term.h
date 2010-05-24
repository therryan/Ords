/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef DEF_TERM_H
#define DEF_TERM_H

#include "../utils/utils.h"

class DefinitionTerm
{
	private:
		string _term;
		string _descr;
		
	public:
		DefinitionTerm();
		DefinitionTerm(string term, string descr);
		
		string getTerm();
		string getDescr();
		
		void setTerm(string term);
		void setDescr(string descr);
		
		string save();	// In the callchain of Collection::save()
		
		string repr();	// Smart representation
};

#endif
