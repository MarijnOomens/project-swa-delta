#include "SceneManager.h"

void SceneManager::update(int time)
{
	for (const auto& s : activeScenes)
	{
		for (const auto& bo : scenes[s])
		{
			bo->update(time);
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
	update(timeFunc(pointer));
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
	update(timeFunc(pointer));
}

void SceneManager::addOverlayScene(const std::string& sceneName)
{
	isSceneSwitched = true;
	isOverlayScene = true;

	activeScenes.push_back(sceneName);
	currentScene = sceneName;
	update(timeFunc(pointer));
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
	for (const auto& s : activeScenes)
	{
		for (const auto& bo : scenes[s])
		{
			if (!isSceneSwitched) {
				bo->handleInput(keyCode, keyboardEvent, mousePos);
			}
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

void SceneManager::passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h)
{
	for (const auto& bo : scenes[currentScene]) {
		if (bo != nullptr && !isSceneSwitched) {
			if (x + w > bo->transform.position.x &&
				bo->transform.position.x + w > x &&
				y + h > bo->transform.position.y &&
				bo->transform.position.y + h > y)
			{
				bo->interact(player);
				isSceneSwitched = true;
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
	if (scenes.count(sceneName) != 0)
	{
		scenes.erase(sceneName);
	}
}

void SceneManager::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects)
{
	scenes[sceneName] = objects;
}

std::shared_ptr<BehaviourObject> SceneManager::getBehaviourObject(CollidingComponent* collidingComponent)
{
	for (const auto& bo : scenes[currentScene])
	{
		auto gameObject = dynamic_cast<GameObject*>(bo.get());
		for (auto& c : gameObject->getComponentsRecursive())
		{
			if (c.get() == collidingComponent) {
				return bo;
			}
		}
	}
}
