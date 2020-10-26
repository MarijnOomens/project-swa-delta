#include "GameManager.h"

GameManager::GameManager() {
	engineFacade = EngineFacade();
	engineFacade.init();
	uiManager = UIManager();
	uiManager.createBaseScreens();
	//for (auto& o : uiManager.screens)
	//{
		//std::cout << o.first << std::endl;
		//for (auto& c : o.second.get()->components) {
		//	this->objects.emplace_back(o);
		//}
	//}
}

void GameManager::RegisterGameObjects() {

}