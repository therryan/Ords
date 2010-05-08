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

#include "question.h"

Question::Question(Dictionary dict)
{
	_dictTitle = dict.getTitle();
	_dict = dict.getDict();	
	_reverse = false;
}

int Question::size()
{
	return _dict.size();
}

void Question::setReverse(bool reverse)
{
	_reverse = reverse;
}

string Question::ask()
{
	cout << "Question::ask()" << endl;
	if (_dict.size() > 0)
	{
		cout << "1" << endl;
		_elem = getRand(_dict.size());
		
		if (_reverse == true)
		{
			return _dict[_elem].getDescr();
		}
		else
		{
			cout << "2" << endl;
			return _dict[_elem].getTerm();
		}
	}

	if (_dict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}

	return false;
}

string Question::answer()
{
	if (_dict.size() > 0)
	{
		if (_reverse == true)
		{
			return _dict[_elem].getTerm();
		}
		return _dict[_elem].getDescr();
	}

	if (_dict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}
	return false;
}

void Question::remove()
{
	if (_dict.size() > 0)
	{
		_dict.erase(_dict.begin() + _elem);
	}
}
