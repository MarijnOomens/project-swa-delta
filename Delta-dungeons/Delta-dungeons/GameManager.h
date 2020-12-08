#pragma once

#include "MainMenuScene.h"
#include "CreditScreenScene.h"
#include "PauseScreenScene.h"
#include "HelpScreenScene.h"
#include "GameOverScreenScene.h"
#include "GameWinScreenScene.h"
#include "LoadSaveScreenScene.h"
#include "DialoguePopupScene.h"
#include "EngineFacade.h"
#include "SceneLoader.h"
#include "DebugUtilities.h"
#include "SceneModifier.h"
#include "AudioUtilities.h"
#include "LevelBuilder.h"

class GameManager {
public:
	GameManager();
	~GameManager() {}

	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void registerAudio(std::map<std::string, std::string> beats);

	void createLevel(std::string levelName);

	static void staticLoadNextLevelCallbackFunction(void* p);
	void loadNextLevelCallbackFunction();

private:
	std::shared_ptr<EngineFacade> engineFacade;

	MainMenuScene mainMenuScene;
	CreditScreenScene creditScreenScene;
	PauseScreenScene pauseScreenScene;
	HelpScreenScene helpScreenScene;
	GameOverScreenScene gameOverScreenScene;
	GameWinScreenScene gameWinScreenScene;
	LoadSaveScreenScene loadSaveScreenScene;
	DialoguePopupScene dialoguePopupScene;

	std::unique_ptr<LevelBuilder> levelBuilder;
	std::vector<Scene> scenes;
	std::vector<std::string> levels{ "Level1", "Dungeon1","Level2", "Dungeon2","Level3", "Dungeon3", "Level4" };
	int currentlevel = 0;
};