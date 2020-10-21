#pragma once
#include "rapidxml_utils.hpp"
#include <iostream>
#include <string>
class XMLParser 
{
public:
	XMLParser();
	void parseXML(char* path);
};