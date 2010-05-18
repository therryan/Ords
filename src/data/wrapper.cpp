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

bool Wrapper::includes(string word)
{
	if (_def.isInDefinition(word)) 
	{
		return true;
	}

	return false;
}

string Wrapper::getWord(string lang)
{
	cout << "WRAPPER CALLED" << endl;
	cout << "WORD: " << _def.getWordByLanguage(lang) << endl;
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
