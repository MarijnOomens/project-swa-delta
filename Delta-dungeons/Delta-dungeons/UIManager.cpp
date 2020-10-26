#include "UIManager.h"

void UIManager::createBaseScreens() {
	std::unique_ptr<MainMenu> mainMenu = std::make_unique<MainMenu>();
	//screens.try_emplace("MainMenu", mainMenu);
}

void UIManager::playDialogue(std::vector<std::string>)
{

}

void UIManager::updateHudHealth(int)
{

}

void UIManager::updateHudCollectedCrystals(int) 
{

}

void UIManager::updateHighScore(int) 
{

}