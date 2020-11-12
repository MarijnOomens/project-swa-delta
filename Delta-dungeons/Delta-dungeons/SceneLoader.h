#pragma once

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "BehaviourObject.h"
#include "EngineFacade.h"

class SceneLoader
{
public:
	static SceneLoader& getInstance();
	void loadScene(const std::string &sceneName, const std::string &fromScene, bool clearPrevious) const;
	void loadPreviousScene() const;
	void addOverlayScene(const std::string& sceneName) const;
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void quitGame() const;

private:
	static SceneLoader sceneLoader;
	std::shared_ptr<EngineFacade> engineFacade;

	SceneLoader() {}
};

