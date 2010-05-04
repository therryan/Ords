// 
// 		src/cli/args.h -- Parsing CLI arguments
// 	
// Takes care of parsing and executing proper things according to the args
//

#ifndef ARGS_H
#define ARGS_H 

#include <fstream>

#include "../file/file.h"
#include "../data/data.h"
#include "../utils/utils.h"

bool parseArgs(int argc, char *argv[]);		// If should continue, return true

namespace args // A namespace that contains all the functions that take care of a certain switch
{
	//void add(string content);
	void help();
	void read(string target);
	void version();
}

#endif
