/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "../utils/utils.h"

#include "file.h"

class Settings
{
	private:
		Settings();
		
		static map<string, string> parse(string data);
		static void set(map<string, string>);
		static string repr();
		static string defaultConfig();
		static string wizard();
		
		static const float _versionNumber;
		static string _dataPath;
				
	public:
		static bool init();
		static bool save();
		
		static void setDirective(string directive, string content);

		static string configPath();
		static string dataPath(string file = "");
		static float version();
};

#endif
