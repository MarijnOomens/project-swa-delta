#pragma once
#include <string>
#include "EngineController.h"

class EngineFacade {
public:
	EngineFacade();
	~EngineFacade();

	void addTexture(std::string name, std::string path);
	std::unique_ptr<EngineController> engineController;
};