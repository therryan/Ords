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

#include "settings.h"

const string Settings::_versionText = "09.05.2010";
const float Settings::_versionNumber = 0.32;
string Settings::_dataPath = "";

bool Settings::init()
{
	while (true)
	{
		// Read the config and if it isn't there, create one with defaults.
		try
		{
			string settings = readData(Settings::configPath());
			break;
		}
		
		catch (string error)
		{
			writeData(Settings::configPath(), Settings::defaultConfig());
		}
	}
	
	return true;
}

bool Settings::save()
{
	writeData(Settings::configPath(), Settings::repr());
	
	return true;
}

string Settings::repr()
{
	string settings;
	
	settings += "datapath=" + Settings::dataPath();
	
	return settings;
}

string Settings::defaultConfig()
{
	string config;
	string home = getenv("HOME");
	
	// Location of the data folder
	config += "datafolder=" + home + "/ords";
	
	return config;
}

string Settings::configPath()
{
	// NOTE: This is the hardcoded location of the default config file
	// Will most likely only work work on *nix systems
	string home = getenv("HOME");
	return home + "/.ords.conf";
}

string Settings::dataPath(string file)
{
	if (file.length() == 0)
	{
		return _dataPath;
	}
	else
	{
		return _dataPath + file + ".ords";
	}
}

float Settings::version()
{
	return _versionNumber;
}

string Settings::versionInfo()
{
	return _versionText;
}
