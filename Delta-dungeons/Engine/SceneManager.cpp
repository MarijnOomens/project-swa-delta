#include "SceneManager.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::loadScene(std::string sceneName, std::string fromScene, bool clearPrevious)
{ 
	if (clearPrevious)
		previousScenes.clear();

	if (!fromScene.empty())
		previousScenes.push_back(fromScene);

	currentScene = sceneName;

	return this->scenes[sceneName];
}

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::loadPreviousScene()
{
	if (!previousScenes.empty())
	{
		std::string previousScene = currentScene = previousScenes.back();
		previousScenes.pop_back();

		return this->scenes[previousScene];
	}

	return this->scenes[currentScene];
}

void SceneManager::registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	this->scenes.try_emplace(sceneName, behaviourObjects);
}