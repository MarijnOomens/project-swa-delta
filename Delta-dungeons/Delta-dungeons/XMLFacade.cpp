#include "XMLFacade.h"

XMLFacade::XMLFacade()
{
	parser = std::make_unique<XMLParser>();
}

XMLFacade::~XMLFacade() {}

std::vector<ParserData> XMLFacade::loadScene(const char* path)
{
	return parser->parseXML(path);
}