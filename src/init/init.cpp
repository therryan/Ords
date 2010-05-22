/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
