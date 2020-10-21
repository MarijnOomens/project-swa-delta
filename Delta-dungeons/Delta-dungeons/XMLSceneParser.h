#pragma once
#include "SceneParser.h"
#include <string>

class XMLSceneParser : public SceneParser {
public:
	XMLSceneParser();
	~XMLSceneParser();
private:
	int loadScene(std::string scenePath);
};
