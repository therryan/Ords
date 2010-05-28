/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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

string Wrapper::get()
{
	string content;
	
	if (_type == "Definition")
	{
		
	}
	else if (_type == "DefinitionTerm")
	{
		content += _dt.getTerm() + "\n" + _dt.getDescr();
	}

	return content;
}

string Wrapper::getTranslation(string word)
{
	if (_type == "Definition")
	{
	
	}
	else if (_type == "DefinitionTerm")
	{
		if (_dt.getTerm() == word)
		{
			return _dt.getDescr();
		}
		else if (_dt.getDescr() == word)
		{
			return _dt.getTerm();
		}
	}
	else if (_type == "Conjugation")
	{
	
	}
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
