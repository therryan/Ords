#include "dictionary.h"

Dictionary::Dictionary(string title)
{
	_dictTitle = title;
}

Dictionary::Dictionary(Definition def, string title)
{
	_dict.push_back(def);
	_dictTitle = title;
}

Dictionary::Dictionary(DefinitionTerm dt, string title)
{
	_dtDict.push_back(dt);
	_dictTitle = title;
}

string Dictionary::getTitle()
{
	return _dictTitle;
}

vector<Definition> Dictionary::getDefDict()
{
	return _dict;
}

vector<DefinitionTerm> Dictionary::getDtDict()
{
	return _dtDict;
}

void Dictionary::load(string file)
{	
	string data;
	
	try
	{
		data = readData(Settings::dataPath() +
				    	file + ".ords");
	}
	
	catch (string error)
	{
		cerr << error << endl;
	}
					
	vector<string> dict = split(data, "\n"); // Splits to lines
				
	for (unsigned int i = 0; i < dict.size(); i++)
	{
		vector<string> def = split(dict[i], ";");
		
		for (unsigned int i = 0; i < def.size(); i++)
		{						
			vector<string> word = split(def[i], ":");
			
			if (word.size() == 2) // Must contain two elements
			{
				// DTs are in the form of X:>Z;
				if (word[1].substr(0, 1) == ">")
				{
					_dtDict.push_back(DefinitionTerm(word[0], word[1].substr(1)));
				}
				
				// Defs are in the form of X:Y;
				else
				{
					_dict.push_back(Definition(word[0], word[1]));
				}
			}						
		}				
	}
}

// Call save() on all defs and dts
void Dictionary::save()
{
	string data;
	
	for (unsigned int i = 0; i < _dict.size(); i++)
	{
		data += _dict[i].save();
	}
	
	for (unsigned int i = 0; i < _dtDict.size(); i++)
	{
		data += _dtDict[i].save();
	}
	
	writeData(Settings::dataPath() + _dictTitle + ".ords", data);
}

void Dictionary::add(Definition def)
{
	_dict.push_back(def);
}

void Dictionary::add(DefinitionTerm dt)
{
	_dtDict.push_back(dt);
}

void Dictionary::add(string word, string translation,
					 string langWord, string langTranslation)
{
	Definition def;
	def.add(word, langWord);
	def.add(translation, langTranslation);
	_dict.push_back(def);
}

// Calls repr() on all defs and dts
string Dictionary::repr()
{
	string defs;
	
	defs += "Definitions of words:\n\n";
	
	for (unsigned int i = 0; i < _dict.size(); i++)
	{
		defs += _dict[i].repr();
	}
	
	defs += "Definitions of terms:\n\n";
	
	for (unsigned int i = 0; i < _dtDict.size(); i++)
	{
		defs += _dtDict[i].repr();
	}
	
	return defs;
}