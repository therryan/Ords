/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

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
