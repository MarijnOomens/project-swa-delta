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

	std::vector<std::shared_ptr<BehaviourObject>>& loadScene(const std::string& sceneName);
	void registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>>& behaviourObjects);


private:
	std::map<std::string, std::vector<std::shared_ptr<BehaviourObject>>> scenes;

};