#pragma once
#include "SceneParser.h"
#include <string>
#include "XMLFacade.h"

class XMLSceneParser : public SceneParser {
public:
	XMLSceneParser();
	~XMLSceneParser();

	std::unique_ptr<XMLFacade> facade;

private:
	int loadScene(const char* path);
};
