#pragma once

#include "XMLParser.h"
#include "PokemonParserData.h"

class XMLFacade
{
public:
	XMLFacade() {}
	~XMLFacade() {}

	std::vector<std::shared_ptr<ParserData>> loadScene(const std::string& path);
	std::vector<std::shared_ptr<PokemonParserData>> loadPokemon(const std::string& path);
private:
	XMLParser parser;
};