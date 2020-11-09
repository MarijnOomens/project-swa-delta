#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "BehaviourObject.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	std::vector<std::shared_ptr<BehaviourObject>> loadScene(std::string sceneName, std::string fromScene, bool clearPrevious);
	std::vector<std::shared_ptr<BehaviourObject>> loadPreviousScene();
	void registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);


private:
	std::map<std::string, std::vector<std::shared_ptr<BehaviourObject>>> scenes;
	std::vector<std::string> previousScenes;
	std::string currentScene;

};