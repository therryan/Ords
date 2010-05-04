#include "question.h"

Question::Question(Dictionary dict)
{
	_dictTitle = dict.getTitle();
	_defDict = dict.getDefDict();
	_dtDict = dict.getDtDict();
}

int Question::size()
{
	return _defDict.size() + _dtDict.size();
}

string Question::ask()
{
	if (_dtDict.size() > 0)
	{
		_dtElem = getRand(_dtDict.size());
		return _dtDict[_dtElem].getTerm();		
	}

	if (_defDict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}
}

string Question::answer()
{
	if (_dtDict.size() > 0)
	{
		return _dtDict[_dtElem].getDescr();
	}

	if (_defDict.size() > 0)
	{
		cout << "Definitions exist!" << endl;
	}
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
