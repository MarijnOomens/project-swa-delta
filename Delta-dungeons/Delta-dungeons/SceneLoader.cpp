#include "SceneLoader.h"

SceneLoader SceneLoader::sceneLoader;

SceneLoader& SceneLoader::getInstance()
{
	return sceneLoader;
}

void SceneLoader::loadScene(std::string sceneName, std::string fromScene, bool clearPrevious)
{
	engineFacade->loadScene(sceneName, fromScene, clearPrevious);
}

void SceneLoader::loadPreviousScene()
{
	engineFacade->loadPreviousScene();
}

void SceneLoader::addOverlayScene(const std::string& sceneName)
{
	engineFacade->addOverlayScene(sceneName);
}

void SceneLoader::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}