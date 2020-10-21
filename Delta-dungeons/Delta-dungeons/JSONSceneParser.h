#pragma once
#include "SceneParser.h"
#include <string>

class JSONSceneParser : public SceneParser {
public:
	JSONSceneParser();
	~JSONSceneParser();
private:
	int loadScene(std::string scenePath);
};
