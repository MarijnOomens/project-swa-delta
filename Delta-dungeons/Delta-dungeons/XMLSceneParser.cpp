#include "XMLSceneParser.h"

/// <summary>
/// XMLSceneParser is a child of the SceneParser. This class is the connection between Scene and the XMLFacade.
/// </summary>

XMLSceneParser::XMLSceneParser()
{
	facade = std::make_unique<XMLFacade>();
}

XMLSceneParser::~XMLSceneParser() {}

/// <summary>
/// This method calls the XMLFacade so the Scene can make Tiles.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>Returns a vector with ParserData objects so the Scene can convert these into Tiles.</returns>

std::vector<std::shared_ptr<Tile>> XMLSceneParser::loadScene(const char* path)
{
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::vector<std::shared_ptr<ParserData>> data = facade->loadScene(path);

	for (std::shared_ptr<ParserData> tile : data)
	{
		int first = tile.get()->tileId[0] - 48;
		if (tile.get()->tileId[1]) {
			int second = tile.get()->tileId[1] - 48;
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, second, tile.get()->isCollider));
		}
		else
		{
			tileMap.emplace_back(std::make_shared<Tile>(std::stoi(tile.get()->x), std::stoi(tile.get()->y), first, tile.get()->isCollider));
		}
	}
	return tileMap;
}

/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for equipment only.</returns>

std::vector<std::shared_ptr<ParserData>> XMLSceneParser::getEquipmentDataList(const char* path)
{
	return facade->getEquipmentDataList(path);
}