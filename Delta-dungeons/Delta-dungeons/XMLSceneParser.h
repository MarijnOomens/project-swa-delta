#pragma once

#include "SceneParser.h"
#include <string>
#include "XMLFacade.h"
#include "Scene.h"
#include <list>
#include "ParserData.h"
#include "Tile.h"

class XMLSceneParser : public SceneParser {
public:
	XMLSceneParser();
	~XMLSceneParser();

	std::unique_ptr<XMLFacade> facade;
	std::shared_ptr<Scene> scene;

	std::vector<std::shared_ptr<Tile>> loadScene(const char* path);
private:
};
