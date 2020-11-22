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
	currentScene = sceneName;
	currentObjects = scenes[currentScene];
	isSceneSwitched = true;
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

	currentObjects.clear();

	for (auto& s : activeScenes) {
		for (auto& o : scenes[s]) {
			currentObjects.emplace_back(o);
		}
	}

	isSceneSwitched = true;
	update();
}

void SceneManager::addOverlayScene(const std::string& sceneName)
{
	isSceneSwitched = true;

	activeScenes.push_back(sceneName);
	currentScene = sceneName;
	for (auto& c : scenes[sceneName])
	{
		currentObjects.emplace_back(c);
	}
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

void SceneManager::addObjectToScene(const std::shared_ptr<BehaviourObject>& addObject)
{
	if (currentScene != "") 
	{
		currentObjects.emplace_back(addObject);
	}
	isSceneSwitched = true;
}

void SceneManager::deleteObjectFromScene(const std::shared_ptr<BehaviourObject>& deletedObject)
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
	for (const auto& bo : currentObjects) {
		if (bo != nullptr) {
			if (bo->transform.position.x == x && bo->transform.position.y == y)
			{
				bo->interact();
			}
		}
	}
	
}