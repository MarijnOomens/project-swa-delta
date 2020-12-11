#pragma once

#include "BehaviourObject.h"
#include "TextureAssetManager.h"
#include "FontAssetManager.h"
#include "AudioAssetManager.h"
#include "GameObject.h"
#include "Input.h"
#include "RenderFacade.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "TextComponent.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include <vector>
#include "Collision.h"
#include "AudioManager.h"

// Engincontroller class
//
// This class is the main controller class of the Engine, where all other controllers and managers get instantiated and passed into other objects.

class EngineController {
public:
	EngineController(const std::string& title, int screenWidth, int screenHeight, bool fullScreen);
	~EngineController() {}

	void initRenderer(const std::string& title, int width, int height, bool fullscreen);

	static void staticPassCameraDimensionFunction(void* p, const Transform& dimensions);
	void passCameraDimensionFunction(const Transform& dimensions);


	static void staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void addTexture(const std::string& name, const std::string& path);
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void registerAudio(std::map<std::string, std::string> tracks);
	void startGame();
	void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	void transitionScene();
	void createCamera(int x, int y) const;
	void passPlayerPosition(int x, int y);
	void pauseScreen();
	void quitGame() const;
	int getFPS() const;
	void slowDownGame() const;
	void speedUpGame() const;
	void resetSpeedGame() const;
	void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y);
	void passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w);
	void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider);
	void gameOver();
	void checkGameOver();
	void checkTransition()const;
	void playAudio(const std::string& trackName, bool looped);
	void deleteScene(const std::string& sceneName);
	void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects);

private:
	std::vector<int> hudLayers;
	std::shared_ptr<RenderFacade> renderFacade;
	std::shared_ptr<TextureManager> textureManager;
	std::shared_ptr<FontManager> fontManager;
	std::unique_ptr<AudioManager> audioManager;
	std::shared_ptr<TextureAssetManager> textureAssetManager;
	std::shared_ptr<FontAssetManager> fontAssetManager;
	std::shared_ptr<AudioAssetManager> audioAssetManager;
	std::shared_ptr<Input> input;
	SceneManager sceneManager;
	std::shared_ptr<Collision> collision;
	bool isGameOver = false;
	int timer = 30;
};