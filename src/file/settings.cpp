#include "settings.h"

const string Settings::versionText = "06.05.2010";
const float Settings::versionNumber = 0.31;

string Settings::helpPath()
{
	return "../ords/help";
}

string Settings::configPath()
{
	return "../ords/ords.conf";
}

string Settings::dataPath(string file)
{
	if (file.length() == 0)
	{
		return "../data/";
	}
	else
	{
		return "../data/" + file + ".ords";
	}
}

float Settings::version()
{
	return versionNumber;
}

string Settings::versionInfo()
{
	return versionText;
}
