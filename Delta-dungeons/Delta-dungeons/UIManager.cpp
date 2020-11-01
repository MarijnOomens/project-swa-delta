#include "UIManager.h"

void UIManager::playDialogue(std::vector<std::string>) {}
void UIManager::createBaseScreens() {
	//std::shared_ptr<MainMenu> mainMenu = std::make_shared<MainMenu>();
	//screens.try_emplace("MainMenu", mainMenu);

	std::shared_ptr<CreditScreen> credits = std::make_shared<CreditScreen>();
	screens.try_emplace("Credits", credits);


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

std::map<std::string, std::string> UIManager::passTextures()
{
	std::map<std::string, std::string> totalTextures;
	for (auto& screen : screens) {
		for (auto& t : screen.second.get()->textures) {
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

std::map<std::string, std::string> UIManager::passFonts()
{
	std::map<std::string, std::string> totalFonts;
	for (auto& screen : screens) {
		for (auto& t : screen.second.get()->fonts) {
			totalFonts.try_emplace(t.first, t.second);
		}
	}
	return totalFonts;
}