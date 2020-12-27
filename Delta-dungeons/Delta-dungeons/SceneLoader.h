#pragma once

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "BehaviourObject.h"
#include "EngineFacade.h"
#include "GameState.h"

typedef void(*cbLoadScene) (void*, const std::string&);

class SceneLoader
{
public:
	static SceneLoader& getInstance();
	void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious, bool isLevel) const;
	void loadPreviousScene() const;
	void addOverlayScene(const std::string& sceneName) const;
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void setLoadSceneCallback(void* p, cbLoadScene ls);
	void quitGame() const;
	void setCurrentLevel(std::string levelName);
	std::string getCurrentLevel();

private:
	static SceneLoader sceneLoader;
	std::shared_ptr<EngineFacade> engineFacade;
	std::string currentLevel;
	void* p;
	cbLoadScene ls;
	SceneLoader() {}
};

