#pragma once
#include "Scene.h"
#include <list>

class SceneManager {
private:
	std::vector<Scene> scenes;

public:
	SceneManager();
	~SceneManager();
	int LoadScene(int scene);
};