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
