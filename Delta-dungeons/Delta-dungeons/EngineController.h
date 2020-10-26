#pragma once
#include "BehaviourObject.h"
#include "SceneManager.h"
#include "RenderFacade.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "AssetManager.h"
#include "Input.h"
#include <vector>

/// Enginecontroller class
///
/// This class is the main controller class of the Engine, where all other controllers and managers get instantiated and passed into other objects.

class EngineController {
public:
		EngineController();
		~EngineController();
		void update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects);
		static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
		void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
		void addTexture(std::string name, std::string path);
		void registerBehaviourObjects(std::vector<std::unique_ptr<BehaviourObject>> objects);

private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::vector<int> hudLayers;
	std::shared_ptr<SceneManager> sceneManager;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<Input> input;

	void initRenderer(const char* title, int width, int height, bool fullscreen);
	void startGame();
};