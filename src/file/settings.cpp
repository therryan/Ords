/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "settings.h"

const float Settings::_versionNumber = 0.43;
string Settings::_dataPath = "";

bool Settings::init()
{
	string settings;
	
	while (true)
	{
		// Read the config and if it isn't there, create one with defaults.
		try
		{
			settings = readData(Settings::configPath());
			break;
		}
		
		catch (string error)
		{
			writeData(Settings::configPath(), Settings::wizard());
		}
	}
	
	map<string, string> config = Settings::parse(settings);
	Settings::set(config);
	
	return true;
}

map<string, string> Settings::parse(string data)
{
	map<string, string> config;
	
	vector<string> directives = split(data, "\n");
	
	for (unsigned int i = 0; i < directives.size(); i++)
	{
		vector<string> tmp = split(directives[i], "=");
				
		if (tmp.size() == 2)
		{
			if (tmp[0] == "datapath")
			{
				config["dataPath"] = tmp[1];
			}
		}
	}
	
	return config;
}

void Settings::set(map<string, string> config)
{
	Settings::_dataPath = config["dataPath"];
}

bool Settings::save()
{
	writeData(Settings::configPath(), Settings::repr());
	
	return true;
}

string Settings::repr()
{
	string settings;
	
	settings += "datapath=" + Settings::_dataPath;
	
	return settings;
}

string Settings::defaultConfig()
{
	string config;
	string home = getenv("HOME");
	
	// Location of the data folder
	config += "datapath=" + home + "/ords";
	
	return config;
}

string Settings::wizard()
{
	string config;
	
	cout << "It appers that this is the first time you have launched this program. " <<
			"Do you want to set the settings now (0) or just use the defaults (1, not recommended)?" << endl;

	int ans = getInt();

	if (ans == 1)
	{
		return Settings::defaultConfig();
	}

	string datapath;
	cout << "Where do you want the data files to be? (Default is ~)" << endl;
	getline(cin, datapath);

	// For now we can just return the defaultconfig but in the future when there are
	// more settings we'll have to do some work here
	if (datapath.length() == 0)
	{
		return Settings::defaultConfig();
	}
	else
	{
		config += "datapath=" + datapath + "/";
	}

	return config;
}

void Settings::setDirective(string directive, string content)
{
	if (directive == "datapath" && content.length() > 0)
	{
		_dataPath = content;
	}
}

string Settings::configPath()
{
	// NOTE: This is the hardcoded location of the default config file
	// Will most likely only work work on *nix systems
	string home = getenv("HOME");
	return home + "/.ords.conf";
}

// There are '/'s so that if there's no slash in 'dataPath', thw world won't come to an end 
string Settings::dataPath(string file)
{
	if (file.length() == 0)
	{
		return _dataPath + "/";
	}
	else
	{
		return _dataPath + "/" + file + ".ords";
	}
}

float Settings::version()
{
	return _versionNumber;
}

