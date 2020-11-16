#pragma once

#include "rapidxml_utils.hpp"
#include <iostream>
#include <string>
#include <list>
#include "ParserData.h"
#include "PokemonParserData.h"

class XMLParser
{
public:
	XMLParser() {}
	~XMLParser() {}

	std::vector<std::shared_ptr<ParserData>> parseXML(const std::string& path);
	std::vector<std::shared_ptr<PokemonParserData>> loadPokemon(const std::string& path);
};