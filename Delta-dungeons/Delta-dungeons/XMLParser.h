#pragma once

#include "rapidxml_utils.hpp"
#include <iostream>
#include <string>
#include <list>
#include "ParserData.h"
#include "PokemonParserData.h"
#include "NPCParserData.h"
#include "PuzzleParserData.h"

class XMLParser
{
public:
	XMLParser() {}
	~XMLParser() {}

	std::vector<std::shared_ptr<ParserData>> parseXML(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> parsePuzzleLevel(const std::string& path);

	std::vector<std::shared_ptr<PokemonParserData>> loadPokemon(const std::string& path);
	std::vector<std::shared_ptr<NPCParserData>> loadNPC(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getPuzzleBoundData(const std::string& path);

	std::shared_ptr<ParserData> getPlayerPosition(const std::string& path);
};