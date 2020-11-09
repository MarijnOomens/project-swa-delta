#include "SceneManager.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

std::vector<std::shared_ptr<BehaviourObject>>& SceneManager::loadScene(const std::string& sceneName)
{ 
	return this->scenes[sceneName];
}

void SceneManager::registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>>& behaviourObjects)
{
	this->scenes.try_emplace(sceneName, behaviourObjects);
}