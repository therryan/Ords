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
// 		src/data/wrapper.h -- The Wrapper class
// 	
// The Wrapper class can hold any definition-object, like a Definition, a DefinitionTerm or a Conjugation

#ifndef WRAPPER_H
#define WRAPPER_H

#include "../utils/utils.h"

#include "definition.h"
#include "def_term.h"
#include "conjugation.h"

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

		// For DefinitionTerm
		string getTerm();
		string getDescr();

		string type();

		string save();
		string repr();
};

#endif
