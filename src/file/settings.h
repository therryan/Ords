/* *** Copyright 2010 Teemu Vasama ***
 * 		This file is part of Ords, which is free software so you can
 * redistribute it and modify it under the terms and conditions of the GPLv3,
 * (GNU General Public License version 3) made by the FSF.
 * 		There is NO WARRANTY whatsoever (See LICENSE for details).
 * 		You can find the GPLv3 license in the LICENSE file or
 * by going to <http://www.gnu.org/licenses/> */

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
		static const string _versionText;
		static string _dataPath;
				
	public:
		static bool init();
		static bool save();
		
		static void setDirective(string directive, string content);

		static string configPath();
		static string dataPath(string file = "");
		static float version();
		static string versionInfo();
};

#endif
