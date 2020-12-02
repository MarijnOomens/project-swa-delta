#pragma once

#include "SceneParser.h"
#include "XMLFacade.h"
#include "ParserData.h"
#include "Tile.h"
#include <string>
#include "PokemonParserData.h"

class XMLSceneParser : public SceneParser
{
public:
	XMLSceneParser() {}
	~XMLSceneParser() {}

	std::vector<std::shared_ptr<Tile>> loadScene(const std::string& path);
	std::vector<std::shared_ptr<PokemonParserData>> loadPokemon(const std::string& path);
	std::vector<std::string> loadNPC(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const std::string& path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(const std::string& path);
	std::shared_ptr<ParserData> getPlayerPosition(const std::string& path);

private:
	XMLFacade facade;
};
