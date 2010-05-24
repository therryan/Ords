/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef INIT_H
#define INIT_H 

#include "../utils/utils.h"

#include "../data/collection.h"
#include "../file/settings.h"

// Initializes the program, returns true if everything went fine
bool init();

// Deinitializes the program, also return true if all is OK
bool deinit();		

#endif
