/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
