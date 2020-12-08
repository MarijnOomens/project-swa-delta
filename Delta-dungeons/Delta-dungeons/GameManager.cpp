#include "GameManager.h"

/// <summary>
/// Inside the Gamemanager all managers in the game are managed and called when the game needs them.
/// </summary>
GameManager::GameManager()
{
	engineFacade = std::make_shared<EngineFacade>();
	engineFacade->init("Delta Dungeons", 1280, 960, false);
	SceneLoader::getInstance().setEngineFacade(engineFacade);
	DebugUtilities::getInstance().setEngineFacade(engineFacade);
	SceneModifier::getInstance().setEngineFacade(engineFacade);
	AudioUtilities::getInstance().setEngineFacade(engineFacade);

	scenes = { mainMenuScene, creditScreenScene, pauseScreenScene, helpScreenScene, gameOverScreenScene, gameWinScreenScene, loadSaveScreenScene, dialoguePopupScene };

	createLevel(levels[currentlevel]);

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

void GameManager::createLevel(std::string levelName)
{
	SceneLoader::getInstance().setCurrentLevel(levels[currentlevel]);
	levelBuilder = std::make_unique<LevelBuilder>(levelName, engineFacade);
	levelBuilder->setWorld();
	levelBuilder->setNPCs();
	levelBuilder->setEquipment();
	levelBuilder->setPokemon();
	Vector2D camPosition = levelBuilder->setPlayer();
	levelBuilder->setHud();
	scenes.emplace_back(levelBuilder->getResult());
	engineFacade->createCamera(camPosition.x, camPosition.y);
}
