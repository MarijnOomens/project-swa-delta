#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "BehaviourObject.h"

class SceneManager {
public:
	SceneManager() {};
	~SceneManager() {};

	std::vector<std::shared_ptr<BehaviourObject>> loadScene(const std::string& sceneName,const std::string& fromScene,const bool clearPrevious);
	void registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>>& behaviourObjects);
	std::vector<std::shared_ptr<BehaviourObject>> loadPreviousScene();
	std::vector<std::shared_ptr<BehaviourObject>> addOverlayScene(const std::string& sceneName);
	int getActiveScenesSize();

private:
	std::map<std::string, std::vector<std::shared_ptr<BehaviourObject>>> scenes;
	std::vector<std::string> activeScenes;
	std::vector<std::string> previousScenes;
	std::string currentScene;

};