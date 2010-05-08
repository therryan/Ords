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

const string Settings::versionText = "06.05.2010";
const float Settings::versionNumber = 0.31;

string Settings::helpPath()
{
	return "../ords/help";
}

string Settings::configPath()
{
	return "../ords/ords.conf";
}

string Settings::dataPath(string file)
{
	if (file.length() == 0)
	{
		return "../data/";
	}
	else
	{
		return "../data/" + file + ".ords";
	}
}

float Settings::version()
{
	return versionNumber;
}

string Settings::versionInfo()
{
	return versionText;
}
