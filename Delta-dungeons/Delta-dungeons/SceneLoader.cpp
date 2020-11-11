#include "SceneLoader.h"

SceneLoader SceneLoader::sceneLoader;

SceneLoader& SceneLoader::getInstance()
{
	return sceneLoader;
}

void SceneLoader::loadScene(const std::string &sceneName, const std::string &fromScene, const bool clearPrevious)const
{
	engineFacade->loadScene(sceneName, fromScene, clearPrevious);
}

void SceneLoader::loadPreviousScene()const
{
	engineFacade->loadPreviousScene();
}

void SceneLoader::addOverlayScene(const std::string& sceneName)const
{
	engineFacade->addOverlayScene(sceneName);
}

void SceneLoader::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}

void SceneLoader::quitGame() const
{
	this->engineFacade->quitGame();
}