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
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(const std::string& path);
	std::shared_ptr<ParserData> getPlayerPosition(const std::string& path);

private:
	XMLParser parser;
};