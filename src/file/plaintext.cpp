/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "plaintext.h"

void writePlaintext(string path, string data)
{	
	ofstream file(path.c_str());
	
	file << data;
	file.close();
}

string readPlaintext(string path)
{
	string fileContents;
	string line;
	ifstream file;
	
	try
	{
		file.open(path.c_str());
	}
	catch (...) // If the file doesn't exist, complain
	{
		throw string("Unable to open file '" + path + "'");
	}
	
	if (file.is_open()) // Makes sure that the file actually works
	{		
		while(!file.eof())
		{
			getline(file, line);
			fileContents += line + "\n";
		}
		
		file.close();
		return fileContents;
	}
	else
	{
		throw string("Unable to open file '" + path + "'");
		return ""; // Optimizing compiler happiness, won't ever be reached though
	}
}
