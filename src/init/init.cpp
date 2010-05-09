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

#include "init.h"

bool init()
{
	// Initializes the Settings and the Collection
	if (Settings::init() && Collection::init())
		{return true;}
	else
		{
			cerr << "Initialization failed, exiting" << endl;
			exit(EXIT_FAILURE);
		}
}
bool deinit()
{
	if (Collection::save() && Settings::save())
	{
		return true;
	}
	else
	{
		return false;
	}
}
