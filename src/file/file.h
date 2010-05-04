// 
// 		src/file/file.h -- Working with files
// 	
// Dummy for including settings and data access classes
// 

#ifndef FILE_H
#define FILE_H

#include "../data/data.h"
#include "../utils/utils.h"

#include "settings.h"
#include "plaintext.h"

/* The following functions are dummies that just call the real functions, 
 * implemented for the distant possibility of doing a MySQL-interface. For now, 
 * they don't really do anything
 */
 
void writeData(string filename, string data);
string readData(string filename);

#endif
