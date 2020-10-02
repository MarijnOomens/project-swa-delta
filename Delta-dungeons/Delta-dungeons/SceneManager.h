#pragma once
#include "Scene.h"
#include <list>

class SceneManager {
private:
	std::list<Scene> scenes;

public:
	int LoadScene(int scene);
};