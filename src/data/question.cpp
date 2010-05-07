#include "question.h"

Question::Question(Dictionary dict)
{
	_dictTitle = dict.getTitle();
	_defDict = dict.getDefDict();
	_dtDict = dict.getDtDict();
	
	_reverse = false;
}

int Question::size()
{
	return _defDict.size() + _dtDict.size();
}

void Question::setReverse(bool reverse)
{
	_reverse = reverse;
}

string Question::ask()
{
	if (_dtDict.size() > 0)
	{
		_dtElem = getRand(_dtDict.size());
		
		if (_reverse == true)
		{
			return _dtDict[_dtElem].getDescr();
		}
		else
		{
			return _dtDict[_dtElem].getTerm();
		}
	}

	if (_defDict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}
	return false;
}

string Question::answer()
{
	if (_dtDict.size() > 0)
	{
		if (_reverse == true)
		{
			return _dtDict[_dtElem].getTerm();
		}
		return _dtDict[_dtElem].getDescr();
	}

	if (_defDict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}
	return false;
}

void Question::remove()
{
	if (_dtDict.size() > 0)
	{
		_dtDict.erase(_dtDict.begin() + _dtElem);
	}

	if (_defDict.size() > 0)
	{
		_defDict.erase(_defDict.begin() + _dtElem);
	}
}
