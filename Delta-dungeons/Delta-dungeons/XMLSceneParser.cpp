#include "XMLSceneParser.h"

/// <summary>
/// XMLSceneParser is a child of the SceneParser. This class is the connection between Scene and the XMLFacade.
/// </summary>

/// <summary>
/// This method calls the XMLFacade so the Scene can make Tiles.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>Returns a vector with ParserData objects so the Scene can convert these into Tiles.</returns>

std::vector<std::shared_ptr<Tile>> XMLSceneParser::loadScene(const std::string& path)
{
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::vector<std::shared_ptr<ParserData>> data = facade.loadScene(path);

	for (std::shared_ptr<ParserData> tile : data)
	{
		int first = tile->tileId[0] - 48;
		if (tile->tileId[1]) {
			int second = tile->tileId[1] - 48;
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile->x), std::stoi(tile->y), first, second, tile->isCollider, tile->isTrigger));
		}
		else
		{
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile->x), std::stoi(tile->y), first, tile->isCollider, tile->isTrigger));
		}
	}
	return tileMap;
}

std::vector<std::shared_ptr<PokemonParserData>> XMLSceneParser::loadPokemon(const std::string& path)
{
	return facade.loadPokemon(path);
}
/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for equipment only.</returns>

std::vector<std::shared_ptr<ParserData>> XMLSceneParser::getEquipmentDataList(const std::string& path)
{
	return facade.getEquipmentDataList(path);
}

std::vector<std::shared_ptr<ParserData>> XMLSceneParser::getNPCDataList(const std::string& path)
{
	return facade.getNPCDataList(path);
}