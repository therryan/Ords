#include "settings.h"

// WARNING! Must be changed manually, hardcoded for now!
//const string Settings::rootPath = "/Users/teemu/Koodaus/Software/Ords/";
const string Settings::rootPath = "/home/teemuvas/Tieva1/ords/"; // Is this correct??
const string Settings::versionText = "04.5.2010";
const float Settings::versionNumber = 0.2;

string Settings::helpPath()
{
	return rootPath + ".ords/help";
}

string Settings::configPath()
{
	return rootPath + ".ords/ords.conf";
}

string Settings::dataPath()
{
	return rootPath + "data/";
}

float Settings::version()
{
	return versionNumber;
}

string Settings::versionInfo()
{
	return versionText;
}
