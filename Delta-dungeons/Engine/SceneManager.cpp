#include "SceneManager.h"

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::loadScene(const std::string& sceneName,const std::string& fromScene, const bool clearPrevious)
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

std::vector<std::shared_ptr<BehaviourObject>> SceneManager::loadPreviousScene()
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

int SceneManager::getActiveScenesSize() 
{
	return activeScenes.size();
}

void SceneManager::updateActiveScene(std::vector<std::shared_ptr<BehaviourObject>> object)
{
	if (scenes.size() > 0) 
	{
		scenes.erase(currentScene);
		scenes.find(currentScene)->second = object;
		/*auto test = std::find(scenes.find(currentScene)->second.begin(), scenes.find(currentScene)->second.end(), object);
		if (test != scenes.find(currentScene)->second.end())
		{
			scenes.find(currentScene)->second.erase = 
		}
		else 
		{
			scenes.find(currentScene)->second.emplace_back(object);
		}*/
	}
}