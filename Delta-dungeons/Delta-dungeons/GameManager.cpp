#include "GameManager.h"

GameManager::GameManager() {
	engineFacade = EngineFacade();
	engineFacade.init();
	uiManager = UIManager();
	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());
	registerBehaviourObjects();
	engineFacade.startGame();
}

void GameManager::registerBehaviourObjects() {
	for (auto& o : uiManager.screens)
	{
		for (auto& c : o.second.get()->getComponentsRecursive()) {
			this->objects.emplace_back(c);
		}
	}
	engineFacade.registerBehaviourObjects(objects);
}

void GameManager::registerTextures(std::map<std::string, std::string> textures) {
	engineFacade.registerTextures(textures);
}