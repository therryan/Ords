/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "args_parser.h"

vector<string> ArgsParser::_args;
string ArgsParser::_error = "";
string ArgsParser::_flag = "";
string ArgsParser::_param = "";

void ArgsParser::setNext()
{
	if (_args.size() > 0)
	{
		
		if (_args[0].substr(0, 1) == "-")
		{
			
			if (_args[0].substr(0, 2) == "--")
			{
				
				// The minimum is "--ab". "--" or just "--a" won't cut it
				if (_args[0].size() > 3)
				{
					// For "ords --blah"
					_flag = _args[0].substr(2);
				}
			}
			else
			{
				
				// We only want something that is exactly formatted like "-a"
				if (_args[0].size() == 2)
				{
					// For "ords -b"
					_flag = _args[0].substr(1);
				}
			}
		}
		
		// For the optional parameter
		if (_args.size() > 1)
		{
			
			if (_args[1].substr(0, 1) == "-" || _args[1].substr(0, 2) == "--") {}
			else
			{
				_param = _args[1];
			}
		}

		if (_flag.empty())
		{
			_error = _args[0];
		}
		else
		{
			// So that 'unknown argument' can catch a flag that passes the above tests
			// but isn't any of the supported ones
			_error = _flag;
		}
	}
}

int ArgsParser::argsLeft()
{
	return _args.size();
}

void ArgsParser::load(vector<string> args)
{
	_args = args;
	ArgsParser::setNext();
}

void ArgsParser::load(int argc, char *argv[])
{
	vector<string> vectorArgs;
	
	// Transitions all the arguments from char** to vector
	for (int i = 1; i < argc; i++) 
	{
		vectorArgs.push_back(argv[i]);
	}
	
	ArgsParser::load(vectorArgs);
}

string ArgsParser::error()
{
	if (!_error.empty())
	{
		return _error;
	}
	
	return "";
}

string ArgsParser::flag()
{
	if (!_flag.empty())
	{
		return _flag;
	}
	
	return "";
}

string ArgsParser::parameter()
{
	if (!_param.empty())
	{
		return _param;
	}
	
	return "";
}

void ArgsParser::remove()
{
	if (_flag.size() > 0)
	{
		if (_param.size() > 0)
		{
			// Erase an extra element
			_args.erase(_args.begin());
		}
	}
	
	// We can always remove one element when we're at this point
	_args.erase(_args.begin());
	
	_error.clear();
	_flag.clear();
	_param.clear();
	ArgsParser::setNext();
}

string ArgsParser::repr()
{
	string repr;
	
	for (unsigned int i = 0; i < _args.size(); i++)
	{
		repr += _args[i] + "\n";
	}
	
	return repr;
}