/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
