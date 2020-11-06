#include "SceneLoader.h"

SceneLoader SceneLoader::sceneLoader;

SceneLoader& SceneLoader::getInstance()
{
	return sceneLoader;
}

void SceneLoader::loadScene(std::string sceneName)
{
	engineFacade->loadScene(sceneName);
}

void SceneLoader::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}