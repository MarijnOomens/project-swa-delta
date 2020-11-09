#include "UIManager.h"

void UIManager::playDialogue(std::vector<std::string>) {}

/// <summary>
/// This methods creates all screens needed for the game to run. Examples are the "MainMenu" and "Credits" screens. These are added into a list.
/// </summary>
void UIManager::createBaseScreens() {
	std::shared_ptr<MainMenu> mainMenu = std::make_shared<MainMenu>();
	screens.try_emplace("MainMenu", mainMenu);
	std::shared_ptr<PauseScreen> pause = std::make_shared<PauseScreen>();
	screens.try_emplace("Pause", pause);
	std::shared_ptr<CreditScreen> credits = std::make_shared<CreditScreen>();
	screens.try_emplace("CreditScreen", credits);
}

void UIManager::updateHudHealth(int) {}

void UIManager::updateHudCollectedCrystals(int) {}

void UIManager::updateHighScore(int) {}

/// <summary>
/// passTextures gets all the textures saved in the screens and gives them back in one big list for the GameManager.
/// </summary>
/// <returns>A map of all textures inside the screens.</returns>
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

/// <summary>
/// passFonts gets all the fonts saved in the screens and gives them back in one big list for the GameManager.
/// </summary>
/// <returns>A map of all fonts inside the screens.</returns>
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