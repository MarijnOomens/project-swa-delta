#pragma once
#include "GameObject.h"
#include "SceneManager.h"
#include "RenderFacade.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Input.h"
class EngineController {
public:
		EngineController();
		~EngineController();
		void Update(std::list<std::shared_ptr<GameObject>>& gameObjects);
		void Render(std::list<std::shared_ptr<GameObject>>& gameObjects);
private:
	std::list<std::shared_ptr<GameObject>> gameObjects;
	std::list<int> hudLayers;
	std::shared_ptr<SceneManager> sceneManager;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	Input input;

	void CreateGameObject();

	void initRenderer(const char* title, int width, int height, bool fullscreen);
	void StartGame();
	void Init();

};