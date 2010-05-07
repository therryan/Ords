#include "question.h"

Question::Question(Dictionary dict)
{
	_dictTitle = dict.getTitle();
	
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
	if (_dict.size() > 0)
	{
		_elem = getRand(_dict.size());
		
		if (_reverse == true)
		{
			return _dict[_elem].getDescr();
		}
		else
		{
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

