#include "XMLFacade.h"

XMLFacade::XMLFacade()
{
	parser = std::make_unique<XMLParser>();
}

XMLFacade::~XMLFacade() {}

std::list<ParserData> XMLFacade::loadScene(const char* path)
{
	std::list<ParserData> parserDataList = parser->parseXML(path);
	return parserDataList;
}