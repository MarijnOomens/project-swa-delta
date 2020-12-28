#pragma once
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "GameStateObject.h"

class SaveSystem
{
public:
	void save(GameStateObject state);
	GameStateObject load();
	void addNodeValue(const char* name, const std::string& value);
private:
	rapidxml::xml_document<> saveDoc;
};