/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

#include "wrapper.h"

Wrapper::Wrapper() {}

Wrapper::Wrapper(Definition def)
{
	_def = def;
	_type = "Definition";
}

Wrapper::Wrapper(DefinitionTerm dt)
{
	_dt = dt;
	_type = "DefinitionTerm";
}

Wrapper::Wrapper(Conjugation conj)
{
	_conj = conj;
	_type = "Conjugation";
}

string Wrapper::getTerm()
{
	if (_type == "DefinitionTerm")
	{
		return _dt.getTerm();
	}

	return "";
}

string Wrapper::getDescr()
{
	if (_type == "DefinitionTerm")
	{
		return _dt.getDescr();
	}

	return "";
}

bool Wrapper::includes(string word, string exclude)
{
	if (_def.isInDefinition(word, exclude)) 
	{
		return true;
	}

	return false;
}

string Wrapper::getWord(string lang)
{
	return _def.getWordByLanguage(lang);
}

string Wrapper::type()
{
	return _type;
}

string Wrapper::save()
{
	if (_type == "Definition")
	{
		return _def.save();
	}
	else if (_type == "DefinitionTerm")
	{
		return _dt.save();
	}
	else if (_type == "Conjugation")
	{
		return _conj.save();
	}

	return "";
}

string Wrapper::repr()
{
	if (_type == "Definition")
	{
		return _def.repr();
	}
	else if (_type == "DefinitionTerm")
	{
		return _dt.repr();
	}
	else if (_type == "Conjugation")
	{
		return _conj.repr();
	}

	return "";
}
