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
	EngineController();
	~EngineController() {}

	void update();
	void initRenderer(const std::string& title, int width, int height, bool fullscreen);
	static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void addTexture(const std::string& name, const std::string& path);
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void startGame();
	void registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	void createCamera(int x, int y) const;
	void passPlayerPosition(int x, int y);
	void pauseScreen();
	void quitGame() const;
	int getFPS() const;
	void slowDownGame() const;
	void speedUpGame() const;
	void resetSpeedGame() const;
	void passInteract(int x, int y);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);

private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::vector<int> hudLayers;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<AssetManager> assetManager;
	std::shared_ptr<Input> input;
	SceneManager sceneManager;

	bool isSceneSwitched = false;

};