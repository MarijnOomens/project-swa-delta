#pragma once
#include "XMLParser.h"

class XMLFacade
{
public:
	XMLFacade();
	~XMLFacade();

	std::vector<ParserData> loadScene(const char* path);
	std::unique_ptr<XMLParser> parser;
};