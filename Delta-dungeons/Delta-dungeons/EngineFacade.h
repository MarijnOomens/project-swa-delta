#pragma once
#include <string>
#include "EngineController.h"

class EngineFacade {
public:
	std::unique_ptr<EngineController> engineController;
	void init();
	void addTexture(std::string name, std::string path);
	void registerBehaviourObjects(std::vector<BehaviourObject> objects);
};