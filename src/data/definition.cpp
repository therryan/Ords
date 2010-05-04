#include "definition.h"

Word::Word(string word)
{
	_word = word;
	_lang = "DEFAULT"; // If lang isn't given, then set to default
}

Word::Word(string word, string lang)
{
	_word = word;
	_lang = lang;
}

string Word::getWord()
{
	return _word;
}
string Word::getLang()
{
	return _lang;
}

/* --- Definition --------------------------------------------------------- */

Definition::Definition() // Is this really that necessary??
{
	
}

Definition::Definition(Word word)
{
	_translations.push_back(word);
}

Definition::Definition(DefinitionTerm dt)
{
	_translations.push_back(Word(dt.getTerm(), dt.getDescr()));
}

Definition::Definition(string word, string lang)
{
	_translations.push_back(Word(word, lang));
}

/* The file format for Defs is as follows:
 
 * LANG:WORD;	for example:
 
 * 		1 Finnish:yksi;English:one;French:un;
 *		2 Finnish:hei;
 *		3 Finnish:koira;French:un chien;
 *		4
 
 * all of the lines have their own Definitions
 * they may contain multiple lang-word pairs.
 * The last line MUST(?) be empty!
 */
string Definition::save()
{
	string data;
	
	for (unsigned int i = 0; i < _translations.size(); i++)
	{
		data += _translations[i].getLang() + ":" +
		 		_translations[i].getWord() + ";";
	}
	data += "\n";
		
	return data;
}

void Definition::add(Word word)
{
	_translations.push_back(word);
}

void Definition::add(string word, string lang)
{
	_translations.push_back(Word(word, lang));
}

/* Definitions are repr'd in the following manner:
 * LANG:(\t)	WORD(\n)
 */
string Definition::repr()
{
	string repr = "\n";
	
	for (unsigned int i = 0; i < _translations.size(); i++)
	{
		repr += _translations[i].getLang() + ": \t";
		repr += _translations[i].getWord() + "\n";
	}
	
	return repr + "\n";
}
