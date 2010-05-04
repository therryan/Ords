// 
// 		src/cli/uifuncs.cpp
// 	
// Contains the functions that ui's parse() calls
//

#ifndef UIFUNCS_H
#define UIFUNCS_H 

#include <iomanip>

#include "../data/data.h"
#include "../utils/utils.h"

using std::setw;

namespace ui
{
	void ask();
	void open(string file = "");
	void newDict(string title = "");
	void use(string title = "");
	void define(string choice = "");
		Definition def_d();
		DefinitionTerm def_dt();
		
	void list();
		void listFile(string file);
		
	void listDicts();
	void help();
}

#endif

