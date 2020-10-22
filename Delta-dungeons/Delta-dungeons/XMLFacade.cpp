#include "XMLFacade.h"

XMLFacade::XMLFacade()
{
	parser = std::make_unique<XMLParser>();
}
// breekt de code somehow, misschien progfout van mij
//XMLFacade::~XMLFacade() {}

std::list<ParserData> XMLFacade::loadScene(const char* path)
{
	std::list<ParserData> parserDataList = parser->parseXML(path);
	return parserDataList;
}