/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef UIFUNCS_H
#define UIFUNCS_H 

#include <iomanip>
#include "../utils/utils.h"

#include "../data/collection.h"
#include "../data/definition.h"
#include "../data/def_term.h"
#include "../data/question.h"
#include "../file/settings.h"

using std::setw;

namespace ui
{
	// If the first argument is empty (i.e. 'open' instead of 'open test'),
	// we know that we need to ask the user about it
	void ask(string language = "",  bool reverse = false);
	void open(string file = "");
	void newDict(string title = "");
	void use(string title = "");
	void define(string choice = "");
		void defDefinition(Definition &def);
		bool defDt(DefinitionTerm &dt);
		
	void list();
	void listFile(string file);
	void listDicts();
	void help();
	void config();
}

#endif
