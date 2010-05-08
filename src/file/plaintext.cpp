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
