#include "XMLSceneParser.h"
#include "Tile.h"

XMLSceneParser::XMLSceneParser()
{
	facade = std::make_unique<XMLFacade>();
	scene = std::make_shared<Scene>();
}

XMLSceneParser::~XMLSceneParser() {}

std::list<Tile*> XMLSceneParser::loadScene(const char* path) {
	std::list<ParserData> data = facade->loadScene(path);
	return scene.get()->makeTiles(data);
}