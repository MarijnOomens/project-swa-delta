#pragma once

#include "XMLParser.h"

class XMLFacade
{
public:
	XMLFacade();
	~XMLFacade();

	std::vector<std::shared_ptr<ParserData>>  loadScene(const char* path);
	std::unique_ptr<XMLParser> parser;
};