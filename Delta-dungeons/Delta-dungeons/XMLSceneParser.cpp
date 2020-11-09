#include "XMLSceneParser.h"
#include "Tile.h"

/// <summary>
/// XMLSceneParser is a child of the SceneParser. This class is the connection between Scene and the XMLFacade.
/// </summary>

XMLSceneParser::XMLSceneParser()
{
	facade = std::make_unique<XMLFacade>();
	scene = std::make_shared<Scene>();
}

XMLSceneParser::~XMLSceneParser() {}

/// <summary>
/// This method calls the XMLFacade so the Scene can make Tiles.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>Returns a vector with ParserData objects so the Scene can convert these into Tiles.</returns>

std::vector<std::shared_ptr<Tile>> XMLSceneParser::loadScene(const char* path)
{
	return scene.get()->makeTiles(facade->loadScene(path));
}

/// <summary>
///  Gets the ParserData only for equipment.
/// </summary>
/// <returns> A list with parserdata for equipment only.</returns>

std::vector<std::shared_ptr<ParserData>> XMLSceneParser::getEquipmentDataList(const char* path)
{
	return facade->getEquipmentDataList(path);
}