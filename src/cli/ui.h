// 
// 		src/cli/ui.h -- The CLI User Interface
// 	
// Defines the interactive mode
//

#ifndef UI_H
#define UI_H

#include "../data/data.h"
#include "../utils/utils.h"

#include "uifuncs.h"

void startUI();
string prompt(string prompt = ">>> ");
bool parse(string input);

#endif

