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

	std::vector<std::shared_ptr<ParserData>> parseXML(const char* path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const char* path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(const char* path);
};