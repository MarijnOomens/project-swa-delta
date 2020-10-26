#include "XMLSceneParser.h"
#include "Tile.h"

XMLSceneParser::XMLSceneParser()
{
	facade = std::make_unique<XMLFacade>();
	scene = std::make_shared<Scene>();
}

XMLSceneParser::~XMLSceneParser() {}

std::vector<std::shared_ptr<Tile>> XMLSceneParser::loadScene(const char* path) {
	return scene.get()->makeTiles(facade->loadScene(path));
}