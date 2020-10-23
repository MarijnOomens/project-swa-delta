#pragma once
#include "rapidxml_utils.hpp"
#include <iostream>
#include <string>
#include <list>
#include "ParserData.h"

class XMLParser
{
public:
	XMLParser();
	~XMLParser();

	std::list<ParserData> parseXML(const char* path);
};