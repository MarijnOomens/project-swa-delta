#pragma once
#include <list>
#include "GameObject.h"
#include "SceneManager.h"

class EngineController {
private:
	std::list<GameObject> gameObjects;
	std::list<int> hudLayers;
	SceneManager sceneManager;

	void CreateGameObject();
	void Update(GameObject gameObjects);
	void Render(std::list<GameObject> gameObjects);
	void Init();

};