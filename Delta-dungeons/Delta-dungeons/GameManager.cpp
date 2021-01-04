#include "GameManager.h"

/// <summary>
/// Inside the Gamemanager all managers in the game are managed and called when the game needs them.
/// </summary>
GameManager::GameManager()
{
	engineFacade = std::make_shared<EngineFacade>();
	engineFacade->init("Delta Dungeons", 1280, 960, false);
	SceneLoader::getInstance().setEngineFacade(engineFacade);
	SceneLoader::getInstance().setLoadSceneCallback(this, createLevelCallback);
	DebugUtilities::getInstance().setEngineFacade(engineFacade);
	SceneModifier::getInstance().setEngineFacade(engineFacade);
	AudioUtilities::getInstance().setEngineFacade(engineFacade);

	scenes = { mainMenuScene, creditScreenScene, pauseScreenScene, helpScreenScene, gameOverScreenScene, gameWinScreenScene, loadSaveScreenScene, dialoguePopupScene, highScoreScreenScene };

	for (auto& s : scenes)
	{
		registerTextures(s.getTextures());
		registerFonts(s.getFonts());
		registerAudio(s.getBeats());
		engineFacade->registerScene(s.name, s.getBehaviourObjects());
	}

	engineFacade->loadScene("MainMenuScreen", "", true);
	engineFacade->startGame();
}

/// <summary>
/// This methods gives the engineFacade all textures to give to the engine.
/// </summary>
void GameManager::registerTextures(std::map<std::string, std::string> textures)
{
	engineFacade->registerTextures(textures);
}

/// <summary>
/// This methods gives the engineFacade all fonts to give to the engine.
/// </summary>
void GameManager::registerFonts(std::map<std::string, std::string> fonts)
{
	engineFacade->registerFonts(fonts);
}

void GameManager::registerAudio(std::map<std::string, std::string> beats)
{
	engineFacade->registerAudio(beats);
}

void GameManager::createLevelCallback(void* p, const std::string& levelName)
{
	((GameManager*)p)->createLevel(levelName);
}

void GameManager::createLevel(const std::string& levelName)
{
	clearScenes();
	currentlevel = std::find(levels.begin(), levels.end(), levelName) - levels.begin();
	SceneLoader::getInstance().setCurrentLevel(levels[currentlevel]);
	if ((GameState::getInstance().getIsPaused() && GameState::getInstance().getIsInputPaused()))
	{
		DebugUtilities::getInstance().pauseInput();
		GameState::getInstance().setIsInputPaused(false);
		GameState::getInstance().setIsPaused(false);
	}
	levelBuilder = std::make_unique<LevelBuilder>(levelName, engineFacade);
	levelBuilder->setWorld();
	levelBuilder->setNPCs();
	levelBuilder->setEquipment();
	levelBuilder->setPokemon();
	levelBuilder->setPuzzle();
	levelBuilder->setPlayer(staticLoadNextLevelCallbackFunction, this);
	Vector2D camPosition = levelBuilder->getPlayerPosition();
	levelBuilder->setHud();
	auto level = levelBuilder->getScene();
	registerTextures(level.getTextures());
	registerFonts(level.getFonts());
	registerAudio(level.getBeats());
	engineFacade->registerScene(levelName, level.getBehaviourObjects());
	engineFacade->createCamera(camPosition.x, camPosition.y);
}

void GameManager::clearScenes()
{
	for (auto& s : levels) 
	{
		engineFacade->deleteScene(s);
	}
}

void GameManager::staticLoadNextLevelCallbackFunction(void* p)
{
	((GameManager*)p)->loadNextLevelCallbackFunction();
}

void GameManager::loadNextLevelCallbackFunction()
{
	engineFacade->deleteScene(levels[currentlevel]);
	currentlevel++;
	createLevel(levels[currentlevel]);
	SceneLoader::getInstance().setCurrentLevel(levels[currentlevel]);
	engineFacade->loadScene(levels[currentlevel], levels[currentlevel - 1], true);
}
