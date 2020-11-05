#include "SceneManager.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::loadScene(std::string sceneName)
{ 
	return this->scenes[sceneName];
}

void SceneManager::registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	this->scenes.try_emplace(sceneName, behaviourObjects);
}