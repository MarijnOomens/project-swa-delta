#pragma once
#include "GameObject.h"
#include "SceneManager.h"
#include "RenderFacade.h"
#include "TextureManager.h"
#include "BehaviourObject.h"
#include "Input.h"

class EngineController {
public:
	EngineController();
	~EngineController();
	void update(std::list<std::shared_ptr<GameObject>>& gameObjects);
	void render(std::list<std::shared_ptr<GameObject>>& gameObjects);
	static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);

private:
	std::list<std::shared_ptr<BehaviourObject>> gameObjects;
	std::list<int> hudLayers;
	std::shared_ptr<SceneManager> sceneManager;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<Input> input;

	void createGameObject();

	void initRenderer(const char* title, int width, int height, bool fullscreen);
	void startGame();
};