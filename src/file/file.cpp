#include "file.h"

using namespace std;

void writeData(string filename, string data)
{
	writePlaintext(filename, data);
}

string readData(string filename)
{
	return readPlaintext(filename);
}

