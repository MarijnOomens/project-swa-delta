#include "SceneManager.h"

void SceneManager::update()
{
	for (const auto& s : activeScenes)
	{
		for (const auto& bo : scenes[s])
		{
			bo->update();
		}
	}
}

void SceneManager::loadScene(const std::string& sceneName, const std::string& fromScene, const bool clearPrevious)
{
	isOverlayScene = false;
	currentScene = sceneName;

	if (clearPrevious)
	{
		previousScenes.clear();
		activeScenes.clear();
	}

	if (!fromScene.empty())
	{
		previousScenes.push_back(fromScene);
	}

	activeScenes.push_back(sceneName);
	for (auto& bo : scenes[currentScene]) {
		bo->start();
	}
	isSceneSwitched = true;
	update();
}

void SceneManager::loadPreviousScene()
{
	if (activeScenes.size() > 1)
	{
		activeScenes.pop_back();
		currentScene = activeScenes.back();
	}
	else if (!previousScenes.empty())
	{
		activeScenes.clear();
		activeScenes.emplace_back(previousScenes.back());
		currentScene = previousScenes.back();
		previousScenes.pop_back();
	}

	isSceneSwitched = true;
	update();
}

void SceneManager::addOverlayScene(const std::string& sceneName)
{
	isSceneSwitched = true;
	isOverlayScene = true;

	activeScenes.push_back(sceneName);
	currentScene = sceneName;
	update();
}

void SceneManager::registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
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
	for (const auto& gameObject : scenes[currentScene])
	{
		if (!isSceneSwitched) {
			gameObject->handleInput(keyCode, keyboardEvent, mousePos);
		}
	}	
}

void SceneManager::addObjectToScene(std::shared_ptr<BehaviourObject> addObject)
{
	if (currentScene != "") 
	{
		scenes[currentScene].emplace_back(addObject);
	}
	isSceneSwitched = true;
}

void SceneManager::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	auto i = std::find(scenes[currentScene].begin(), scenes[currentScene].end(), deletedObject);
	if (i != scenes[currentScene].end())
	{
		scenes[currentScene].erase(i);
	}
	isSceneSwitched = true;
}

void SceneManager::passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w)
{
	for (const auto& bo : scenes[currentScene]) {
		if (bo != nullptr && !isSceneSwitched) {
			if (x + w > bo->transform.position.x &&
				bo->transform.position.x + w > x &&
				y + w > bo->transform.position.y &&
				bo->transform.position.y + w > y)
			{
				bo->interact(player);
			}
		}
	}
}

std::string SceneManager::getCurrentScene()
{
	return currentScene;
}

void SceneManager::deleteScene(const std::string& sceneName)
{
	scenes[sceneName].clear();
}

void SceneManager::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects)
{
	scenes[sceneName] = objects;
}