#include "args.h"

bool parseArgs(int argc, char *argv[])
{
	using namespace std;
	vector<string> args;
	string programName = argv[0];
	
	if (argc == 1)	   // argv[0] is always the name of the program, the size is always >0
		{return true;} // If no arguments are given, go to interavtive mode
		
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++) // Transitions all the arguments from char** to vector
		{
			args.push_back(argv[i]);
		}

		if (args[0] == "-h" ||
		 	args[0] == "--help")
		{
			args::help();
		}
		
		else if ((args[0] == "-r" ||
		 		  args[0] == "--read") && args.size() > 1)
		{
			args::read(args[1]);
		}
		
		else if (args[0] == "-a" ||
				 args[0] == "--add")
		{
			//args::add();
		}
		
		else if (args[0] == "-v")
		{
			args::version();
		}
		
		else	// If an argument is unknown, inform the user about it
		{
			cout << "Unknown argument '" + args[0] + "'" << endl;
			args.erase(args.begin());
		}
	}
	
	return false; // Don't go to the interactive mode
}

namespace args
{
	//void add(string content)
	void help()
	{	
		string helpPath = Settings::helpPath();
		try
		{
			readPlaintext(helpPath);
		}
		catch (string error)
		{
			cout << "ERROR: " + error << endl;
		}	
	}
	void read(string target)
	{
		try
		{
			readData(target);
		}
		catch (string error)
		{
			cout << "ERROR: " + error << endl;
		}	
	}
	void version()
	{
		cout << "ords version " << Settings::version() << endl;
		cout << "version text: " << Settings::versionInfo() << endl;
	}
}
