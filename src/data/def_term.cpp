#include "def_term.h"

DefinitionTerm::DefinitionTerm() // Questioning the existance of this poor thing...
{}

DefinitionTerm::DefinitionTerm(string term, string descr)
{
	_term = term;
	_descr = descr;
}

string DefinitionTerm::getTerm()
{	
	return _term;
}

string DefinitionTerm::getDescr()
{	
	return _descr;
}

void DefinitionTerm::setTerm(string term)
{
	_term = term;
}

void DefinitionTerm::setDescr(string descr)
{
	_descr = descr;
}

/* The file format for DefinitionTerms is this:

 *		TERM:>DESCRIPTION;	as in
 *		hello:>moi;

 * Only one dt can be put on a single line!
 * Again, it would be awesome if the last line was empty
 */
string DefinitionTerm::save()
{
	string data;
	
	data += getTerm() + ":>" +
			getDescr() + ";\n";
		
	return data;
}

/* DTs are repr'd like this:
 
 *		TERM:
 *		(\t)	DESCR(\n)

 * For example:

 *		hello:
 *			moi
 */
string DefinitionTerm::repr()
{
	stringstream ss;
	
	ss << this->getTerm() << ":\n";
 	ss << "\t" << this->getDescr() << "\n";
		
	return ss.str(); 
}
