/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef UI_H
#define UI_H

#include "../utils/utils.h"

#include "uifuncs.h"

void startUI();
string prompt(string prompt = ">>> ");
bool parse(string input);

#endif
