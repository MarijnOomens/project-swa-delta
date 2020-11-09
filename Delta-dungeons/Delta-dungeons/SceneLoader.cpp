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

void SceneLoader::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}