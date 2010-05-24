/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "def_term.h"

DefinitionTerm::DefinitionTerm() {}

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

string DefinitionTerm::save()
{
	string data;
	
	data += getTerm() + ":>" +
			getDescr() + ";\n";
		
	return data;
}

string DefinitionTerm::repr()
{
	stringstream ss;
	
	ss << this->getTerm() << ":\n";
 	ss << "\t" << this->getDescr() << "\n";
		
	return ss.str(); 
}
