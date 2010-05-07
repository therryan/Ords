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
}

string Wrapper::getDescr()
{
	if (_type == "DefinitionTerm")
	{
		return _dt.getDescr();
	}
}

string Wrapper::type()
{
	return _type;
}

string Wrapper::save()
{
	if (_type == "Definition")
	{
		_def.save();
	}
	else if (_type == "DefinitionTerm")
	{
		_dt.save();
	}
	else if (_type == "Conjugation")
	{
		_conj.save();
	}
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
}
