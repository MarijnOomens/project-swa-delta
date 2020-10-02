#pragma once
#include "SceneParser.h"

class JSONSceneParser : public SceneParser {
public:
	JSONSceneParser();
	~JSONSceneParser();
private:
	int LoadScene(int scene);
};
