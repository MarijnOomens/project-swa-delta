#pragma once
#include <string>
#include "EngineController.h"

class EngineFacade {
public:
	std::unique_ptr<EngineController> engineController;
	void init();
	void addTexture(std::string name, std::string path);
	void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void startGame();
};