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
//		src/data/def_term.h -- Contains the DefinitionTerm (dt) class
//
//	It is used in a oneway system (x -> y), in contrast to Definition

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
		
		string save();	// In the callchain for Collection::save()
		
		string repr();	// Smart representation
};

#endif
