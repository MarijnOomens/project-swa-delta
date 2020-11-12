#pragma once

#include "SceneParser.h"
#include "XMLFacade.h"
#include "ParserData.h"
#include "Tile.h"
#include <string>

class XMLSceneParser : public SceneParser
{
public:
	XMLSceneParser() {}
	~XMLSceneParser() {}

	std::vector<std::shared_ptr<Tile>> loadScene(const std::string& path);
private:
	XMLFacade facade;
};
