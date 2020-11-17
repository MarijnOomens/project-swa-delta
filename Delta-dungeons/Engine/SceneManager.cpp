#include "SceneManager.h"

void SceneManager::update()
{
	for (const auto& activeScene : activeScenes) {
		for (const auto& bo : scenes[activeScene])
		{
			bo->update();
		}
	}
}

void SceneManager::loadScene(const std::string& sceneName,const std::string& fromScene, const bool clearPrevious)
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
	isSceneSwitched = true;
}

void SceneManager::loadPreviousScene()
{

	if (activeScenes.size() > 1)
	{
		activeScenes.pop_back();
		//std::vector<std::shared_ptr<BehaviourObject>> tempObjects;

		//for (const auto& a : activeScenes)
		//{
		//	tempObjects.insert(tempObjects.end(), scenes[a].begin(), scenes[a].end());
		//}

		//return tempObjects;
	}

	if (!previousScenes.empty())
	{
		activeScenes.pop_back();
		currentScene = previousScenes.back();
		previousScenes.pop_back();
	}

	isSceneSwitched = true;
	update();
}

void SceneManager::addOverlayScene(const std::string& sceneName)
{
	isSceneSwitched = true;

	activeScenes.push_back(sceneName);
	update();
}

void SceneManager::registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>>& behaviourObjects)
{
	this->scenes.try_emplace(sceneName, behaviourObjects);
}

int SceneManager::getActiveScenesSize() 
{
	return activeScenes.size();
}

void SceneManager::setSceneSwitched(bool isSwitched)
{
	isSceneSwitched = isSwitched;
}

void SceneManager::handleSceneInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) 
{
	for (const auto& activeScene : activeScenes) {
		for (const auto& gameObject : scenes[currentScene])
		{
			if (!isSceneSwitched) {
				gameObject->handleInput(keyCode, keyboardEvent, mousePos);
			}
		}
	}
}

void SceneManager::addObjectToScene(std::shared_ptr<BehaviourObject> addObject)
{
	scenes[currentScene].emplace_back(addObject);
	isSceneSwitched = true;
}

void SceneManager::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	auto i = std::find(scenes[currentScene].begin(), scenes[currentScene].end(), deletedObject);
	if (i != scenes[currentScene].end())
	{
		auto copy = scenes[currentScene];
		auto iooo = std::find(copy.begin(), copy.end(), deletedObject);
		if (iooo != copy.end())
		{
			copy.erase(iooo);
		}
		scenes[currentScene] = copy;
	}
	isSceneSwitched = true;
}