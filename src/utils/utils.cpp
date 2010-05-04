#include "utils.h"

vector<string> split(const string& str, string delimiter)
{
	vector<string> tokens;
	
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiter, 0);

    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiter, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));

        // Skip delimiters. Note the "not_of"
        lastPos = str.find_first_not_of(delimiter, pos);

        // Find next "non-delimiter"
        pos = str.find_first_of(delimiter, lastPos);
    }	
	
	return tokens;
}

string printVector(const vector<string>& vec)
{
	string contents;
	
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		contents += vec[i];
	}
	
	return contents;
}

int getInt(string msg)
{
	string tmp;
	int input;
	
	cout << msg;		// Print out the optional message
	getline(cin, tmp);
	
	stringstream ss;	// Makes sure it's a number
	ss << tmp;
	ss >> input;

	return input;
}

int getRand(int max)
{
	return rand() % max;
}
