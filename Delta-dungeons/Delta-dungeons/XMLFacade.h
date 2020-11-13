#pragma once

#include "XMLParser.h"

class XMLFacade
{
public:
	XMLFacade() {}
	~XMLFacade() {}

	std::vector<std::shared_ptr<ParserData>> loadScene(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(cconst std::string& path);
private:
	XMLParser parser;
};