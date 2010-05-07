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

	public:
		Wrapper();
		Wrapper(Definition def);
		Wrapper(DefinitionTerm dt);
		Wrapper(Conjugation conj);

		string type();
};

#endif
