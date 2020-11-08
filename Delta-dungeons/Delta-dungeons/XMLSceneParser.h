#pragma once

#include "SceneParser.h"
#include "XMLFacade.h"
#include "Scene.h"
#include "ParserData.h"
#include "Tile.h"
#include <string>

class XMLSceneParser : public SceneParser {
public:
	XMLSceneParser();
	~XMLSceneParser();

	std::unique_ptr<XMLFacade> facade;
	std::shared_ptr<Scene> scene;

	std::vector<std::shared_ptr<Tile>> loadScene(const char* path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList();
	
private:
};
