#pragma once

#include "XMLParser.h"

class XMLFacade
{
public:
	XMLFacade() {}
	~XMLFacade() {}

	std::vector<std::shared_ptr<ParserData>> loadScene(const std::string& path);

private:
	XMLParser parser;
};