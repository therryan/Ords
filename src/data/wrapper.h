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
