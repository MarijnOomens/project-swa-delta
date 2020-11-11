#include "SceneManager.h"

std::vector<std::shared_ptr<BehaviourObject>>& SceneManager::loadScene(std::string& sceneName, std::string& fromScene, bool clearPrevious)
{ 
	activeScenes.clear();

	if (clearPrevious)
	{
		previousScenes.clear();
	}

	if (!fromScene.empty())
	{
		previousScenes.push_back(fromScene);
	}

	activeScenes.push_back(sceneName);
	currentScene = sceneName;

	return this->scenes[sceneName];
}

std::vector<std::shared_ptr<BehaviourObject>>& SceneManager::loadPreviousScene()
{

	if (activeScenes.size() > 1)
	{
		activeScenes.pop_back();
		std::vector<std::shared_ptr<BehaviourObject>> tempObjects;

		for (const auto& a : activeScenes)
		{
			tempObjects.insert(tempObjects.end(), scenes[a].begin(), scenes[a].end());
		}

		return tempObjects;
	}

	if (!previousScenes.empty())
	{
		activeScenes.pop_back();
		std::string previousScene = currentScene = previousScenes.back();
		previousScenes.pop_back();

		return this->scenes[previousScene];
	}

	return this->scenes[currentScene];
}

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::addOverlayScene(const std::string& sceneName)
{
	activeScenes.push_back(sceneName);
	return this->scenes[sceneName];
}

void SceneManager::registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>>& behaviourObjects)
{
	this->scenes.try_emplace(sceneName, behaviourObjects);
}