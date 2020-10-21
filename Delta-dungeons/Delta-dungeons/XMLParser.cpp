#include "XMLParser.h"

XMLParser::XMLParser(){}

void XMLParser::parseXML(char* path) {
    rapidxml::file<> xmlFile(path);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    std::cout << doc.first_node()->name()<< std::endl;

}