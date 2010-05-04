#include "init.h"

bool init()
{
	// Not implemented yet
	// Settings::load();

	Collection::init();	// Inits the Collection
	
	// For now, doesn't *really* do anything
	if (true)
		{return true;}
	else
		{exit(EXIT_FAILURE);}
	
}
bool deinit()
{
	Collection::save(); // Saves stuff to disk
	
	// Not implemented yet
	// Settings::save();
	
	return true;
}
