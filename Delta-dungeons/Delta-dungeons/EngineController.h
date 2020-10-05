#pragma once
#include <list>
#include "GameObject.h"
#include "SceneManager.h"
#include "SDLFacade.h"

class EngineController {
public:
		EngineController();
		~EngineController();
private:
	std::list<GameObject> gameObjects;
	std::list<int> hudLayers;
	SceneManager sceneManager;
	SDLFacade* sdlFacade;
	void CreateGameObject();
	void Update(GameObject gameObjects);
	void Render(std::list<GameObject> gameObjects);
	void Init();

};