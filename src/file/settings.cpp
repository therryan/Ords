#include "settings.h"

const string Settings::versionText = "05.05.2010";
const float Settings::versionNumber = 0.2;

string Settings::helpPath()
{
	return "../ords/help";
}

string Settings::configPath()
{
	return "../ords/ords.conf";
}

string Settings::dataPath()
{
	//return rootPath + "data/";
	return "../data/";
}

float Settings::version()
{
	return versionNumber;
}

string Settings::versionInfo()
{
	return versionText;
}
