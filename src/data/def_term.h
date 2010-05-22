/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
