#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "BehaviourObject.h"

class SceneManager {
public:
	bool isOverlayScene = false;

	SceneManager() {}
	~SceneManager() {}

	void update();
	void loadScene(const std::string& sceneName,const std::string& fromScene,const bool clearPrevious);
	void registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	int getActiveScenesSize();
	void setSceneSwitched(bool isSwitched);
	void handleSceneInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y);
	std::string getCurrentScene();
	void deleteScene(const std::string& sceneName);

private:
	std::map<std::string, std::vector<std::shared_ptr<BehaviourObject>>> scenes;
	std::vector<std::string> activeScenes;
	std::vector<std::string> previousScenes;
	std::string currentScene;
	bool isSceneSwitched = false;
};