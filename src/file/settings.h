// 
// 		src/file/settings.h -- Working with config files
// 	
// Writing and reading the config file
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include "../utils/utils.h"

class Settings
{
	private:
		Settings();
		
		static const string rootPath;
		static const float versionNumber;
		static const string versionText;
				
	public:
		static string configPath();
		static string helpPath();
		static string dataPath();
		static float version();
		static string versionInfo();
};

#endif
