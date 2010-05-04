// 
// 		src/misc/init.h -- init and deinit
// 	
// Starts and ends the program, loads/saves appropriate files etc.
//

#ifndef INIT_H
#define INIT_H 

#include "../data/data.h"
#include "../utils/utils.h"

// Initializes the program, returns true if everything went fine
bool init();

// Deinitializes the program, also return true if all is OK
bool deinit();		

#endif
