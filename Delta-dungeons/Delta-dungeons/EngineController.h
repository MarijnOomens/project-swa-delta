#pragma once
#include "BehaviourObject.h"
#include "SceneManager.h"
#include "RenderFacade.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "AssetManager.h"
#include "Input.h"

class EngineController {
public:
		EngineController();
		~EngineController();
		void Update(std::list<std::shared_ptr<BehaviourObject>>& bhObjects);
		static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
		void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
		void addTexture(std::string name, std::string path);
private:
	std::list<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::list<int> hudLayers;
	std::shared_ptr<SceneManager> sceneManager;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<Input> input;

	void createGameObject();

	void initRenderer(const char* title, int width, int height, bool fullscreen);
	void startGame();
};