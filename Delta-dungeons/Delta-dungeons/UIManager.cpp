#include "UIManager.h"

/// <summary>
/// This methods creates all screens needed for the game to run. Examples are the "MainMenu" and "Credits" screens. These are added into a list.
/// </summary>
void UIManager::createBaseScreens() 
{
	std::unique_ptr<MainMenu> mainMenu = std::make_unique<MainMenu>();
	screens.try_emplace("MainMenu", std::move(mainMenu));
	std::unique_ptr<PauseScreen> pause = std::make_unique<PauseScreen>();
	screens.try_emplace("PauseScreen", std::move(pause));
	std::unique_ptr<CreditScreen> credits = std::make_unique<CreditScreen>();
	screens.try_emplace("CreditsScreen", std::move(credits));
	std::unique_ptr<HelpScreen> help = std::make_unique<HelpScreen>();
	screens.try_emplace("HelpScreen", std::move(help));
	std::unique_ptr<GameOverScreen> gameOver = std::make_unique<GameOverScreen>();
	screens.try_emplace("GameOver", std::move(gameOver));
	std::unique_ptr<GameWinScreen> gameWin = std::make_unique<GameWinScreen>();
	screens.try_emplace("GameWin", std::move(gameWin));
	std::unique_ptr<LoadSaveScreen> loadSaveScreen = std::make_unique<LoadSaveScreen>();
	screens.try_emplace("LoadSaveScreen", std::move(loadSaveScreen));
	std::unique_ptr<DialoguePopup> dialoguePopup = std::make_unique<DialoguePopup>();
	screens.try_emplace("Dialogue", std::move(dialoguePopup));

	beats.try_emplace("touch", "Assets/Audio/touch.ogg");
	
}

void UIManager::playDialogue(std::vector<std::string>) {}

void UIManager::updateHudHealth(int param) {}

void UIManager::updateHudCollectedCrystals(int param) {}

void UIManager::updateHighScore(int param) {}

/// <summary>
/// passTextures gets all the textures saved in the screens and gives them back in one big list for the GameManager.
/// </summary>
/// <returns>A map of all textures inside the screens.</returns>
std::map<std::string, std::string> UIManager::passTextures()
{
	std::map<std::string, std::string> totalTextures;
	for (auto& screen : screens) {
		for (auto& t : screen.second->textures) {
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

std::map<std::string, std::string> UIManager::passBeats()
{
	return beats;
}

/// <summary>
/// passFonts gets all the fonts saved in the screens and gives them back in one big list for the GameManager.
/// </summary>
/// <returns>A map of all fonts inside the screens.</returns>
std::map<std::string, std::string> UIManager::passFonts()
{
	std::map<std::string, std::string> totalFonts;
	for (auto& screen : screens) {
		for (auto& t : screen.second->fonts) {
			totalFonts.try_emplace(t.first, t.second);
		}
	}
	return totalFonts;
}