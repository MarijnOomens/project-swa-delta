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
	void loadScene(std::string sceneName);
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);

private:
	static SceneLoader sceneLoader;

	std::shared_ptr<EngineFacade> engineFacade;

	SceneLoader() {}


};

