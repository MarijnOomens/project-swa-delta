#include "SceneManager.h"

void SceneManager::update()
{
	for (const auto& bo : currentObjects)
	{
		bo->update();
	}
}

void SceneManager::loadScene(const std::string& sceneName, const std::string& fromScene, const bool clearPrevious)
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
	currentObjects = scenes[currentScene];
	isSceneSwitched = true;
}

void SceneManager::loadPreviousScene()
{
	for (auto& c : scenes[activeScenes.back()])
	{
		auto i = std::find(currentObjects.begin(), currentObjects.end(), c);
		currentObjects.erase(i);
	}
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
	else if (!previousScenes.empty())
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
	for (auto& c : scenes[sceneName])
	{
		currentObjects.emplace_back(c);
	}
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
		for (const auto& gameObject : currentObjects)
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
	auto i = std::find(currentObjects.begin(), currentObjects.end(), deletedObject);
	if (i != currentObjects.end())
	{
		currentObjects.erase(i);
	}
	isSceneSwitched = true;
}

void SceneManager::passInteract(int x, int y)
{
	for (const auto& as : activeScenes) {
		for (const auto& bo : currentObjects) {
			if (bo->transform.position.x == x && bo->transform.position.y == y)
			{
				bo->interact();
			}
		}
	}
}