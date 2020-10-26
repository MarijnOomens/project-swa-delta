#include "XMLParser.h"
using namespace rapidxml;

XMLParser::XMLParser() {}
XMLParser::~XMLParser() {}


std::vector<std::shared_ptr<ParserData>> XMLParser::parseXML(const char* path) {
	std::vector<std::shared_ptr<ParserData>> parserDataList;
	rapidxml::file<> xmlFile(path);
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("tilemap");

	for (xml_node<>* child = node->first_node(); child; child = child->next_sibling())
	{
		for (xml_node<>* tile = child->first_node(); tile; tile = tile->next_sibling())
		{
			std::shared_ptr<ParserData> p = std::make_shared<ParserData>(tile->first_attribute("x")->value(), tile->first_attribute("y")->value(), tile->first_attribute("tile")->value());
			parserDataList.push_back(p);
		}
	}
	return parserDataList;
}