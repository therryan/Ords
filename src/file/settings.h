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
		
		static const float versionNumber;
		static const string versionText;
				
	public:
		static void init();
		
		static string configPath();
		static string helpPath();
		static string dataPath(string file = "");
		static float version();
		static string versionInfo();
};

#endif
