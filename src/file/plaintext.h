//
//  	src/file/plaintext.h -- Working with data in plaintext files
//
// Writing and reading a string to and from a plaintext file
//

#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <fstream>

#include "../data/data.h"
#include "../utils/using.h"

using std::ifstream;
using std::ofstream;
using std::ios;

void writePlaintext(string filename, string data);
string readPlaintext(string filename);

#endif
