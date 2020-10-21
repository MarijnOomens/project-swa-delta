#include "XMLParser.h"
using namespace rapidxml;
XMLParser::XMLParser(){}

void XMLParser::parseXML(const char* path) {
    rapidxml::file<> xmlFile(path);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>* node = doc.first_node("tilemap");
    for (xml_node<>* child = node->first_node(); child; child = child->next_sibling()) 
    {
        for (xml_node<>* tile = child->first_node(); tile; tile = tile->next_sibling()) 
        {
            std::cout << "X: "<<tile->first_attribute("x")->value()<< " y: " <<tile->first_attribute("y")->value()<<" TileId: "<< tile->first_attribute("tile")->value() << std::endl;
        }
    }

}