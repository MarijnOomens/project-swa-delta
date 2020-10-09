#pragma once
#include "GameObject.h"
#include "SceneManager.h"
#include "SDLFacade.h"

class EngineController {
public:
		EngineController();
		~EngineController();
private:
	std::list<std::unique_ptr<GameObject>> gameObjects;
	std::list<int> hudLayers;
	SceneManager sceneManager;
	SDLFacade* sdlFacade;
	void CreateGameObject();
	void Update(GameObject& gameObjects);
	void Render(std::list<std::unique_ptr<GameObject>> gameObjects);
	void Init();

};