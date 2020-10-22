#include "XMLSceneParser.h"

XMLSceneParser::XMLSceneParser()
{
	facade = std::make_unique<XMLFacade>();
}

XMLSceneParser::~XMLSceneParser() {}

int XMLSceneParser::loadScene(const char* path) {
	facade->loadScene(path);
	return 0;
}