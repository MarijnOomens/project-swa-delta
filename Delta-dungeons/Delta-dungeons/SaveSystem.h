#pragma once
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

class SaveSystem
{
public:
	void save(const std::string& currentLevel, int caughtPokemon, int health, int pokeBalls, int berries, bool hasBoomerang, bool hasRunningShoes, bool runningShoesActivated);
	void addNodeValue(const char* name, const std::string& value);
private:
	rapidxml::xml_document<> saveDoc;
};