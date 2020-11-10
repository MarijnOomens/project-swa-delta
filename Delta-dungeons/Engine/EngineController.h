#pragma once
#include "BehaviourObject.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "Input.h"
#include "RenderFacade.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "TextComponent.h"
#include "GraphicsComponent.h"
#include <vector>

// Engincontroller class
//
// This class is the main controller class of the Engine, where all other controllers and managers get instantiated and passed into other objects.

class EngineController {
public:
	ENGINE_API EngineController();
	ENGINE_API ~EngineController();

	void update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects);
	static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	ENGINE_API void addTexture(std::string name, std::string path);
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures);
	ENGINE_API void registerFonts(std::map<std::string, std::string> fonts);
	ENGINE_API void startGame();
	ENGINE_API void registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	ENGINE_API void loadScene(std::string sceneName, std::string fromScene, bool clearPrevious);
	ENGINE_API void loadPreviousScene();
	ENGINE_API void addOverlayScene(const std::string& sceneName);
	ENGINE_API void createCamera(int x, int y);
	ENGINE_API void passPlayerPosition(int x, int y);
	void pauseScreen();
	ENGINE_API void quitGame();
	ENGINE_API int getFPS();
	void changeSpeed(KeyCodes keyCode);

private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::vector<int> hudLayers;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<Input> input;
	SceneManager sceneManager;

	bool isSceneSwitched = false;

	void initRenderer(const char* title, int width, int height, bool fullscreen);
};