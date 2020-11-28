#include "GameManager.h"

/// <summary>
/// Inside the Gamemanager all managers in the game are managed and called when the game needs them.
/// </summary>
GameManager::GameManager()
{
	engineFacade = std::make_shared<EngineFacade>();
	engineFacade->init();
	SceneLoader::getInstance().setEngineFacade(engineFacade);
	DebugUtilities::getInstance().setEngineFacade(engineFacade);
	SceneModifier::getInstance().setEngineFacade(engineFacade);
	AudioUtilities::getInstance().setEngineFacade(engineFacade);

	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());
	registerFonts(uiManager.passFonts());
	registerAudio(uiManager.passBeats());
	scene = std::make_shared<Scene>();

	for (auto& o : uiManager.screens)
	{
		std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
		behaviourObjects.emplace_back(o.second);
		for (auto& c : o.second->getComponentsRecursive())
		{
			behaviourObjects.emplace_back(c);
		}
		engineFacade->registerScene(o.first, behaviourObjects);
	}

	createLevel(levels[currentlevel]);

	engineFacade->loadScene("MainMenu", "", true);
	engineFacade->startGame();
}

/// <summary>
/// This methods registers all BehaviourObjects from all managers into one big list within the GameManager.
/// </summary>
void GameManager::registerBehaviourObjects()
{

	std::vector<std::shared_ptr<BehaviourObject>> level;
	for (auto& t : scene->getComponentsRecursive())
	{
		level.emplace_back(t);
	}
	level.emplace_back(scene);

	for (auto& o : npcManager.npcs)
	{
		for (auto& n : o.second->getComponentsRecursive())
		{
			level.emplace_back(n);
		}
		level.emplace_back(o.second.get());
	}

	for (auto& o : eqManager.equipments)
	{
		for (auto& n : o.second->getComponentsRecursive())
		{
			level.emplace_back(n);
		}
		level.emplace_back(o.second.get());
	}

	for (auto& o : pokemonManger.pokemon)
	{
		for (auto& n : o.second.get()->getComponentsRecursive())
		{
			level.emplace_back(n);
		}
		level.emplace_back(o.second.get());
	}

	for (auto& c : playerManager.player->getComponentsRecursive())
	{
		level.emplace_back(c);
	}
	level.emplace_back(playerManager.player);

	for (auto& c : hudManager.hud->getComponentsRecursive())
	{
		level.emplace_back(c);
	}
	level.emplace_back(hudManager.hud);
	engineFacade->registerScene(levels[currentlevel], level);
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
	playerManager.createPlayer(staticCheckCollisionCallbackFunction, staticLoadNextLevelCallbackFunction, staticCameraCallbackFunction, staticInteractCallbackFunction, staticGameOverbackFunction, staticUpdateHUDHealthCallbackFunction, this);
	registerTextures(playerManager.passTextures());

	npcManager.createNPC(levelName);
	registerTextures(npcManager.passTextures());

	pokemonManger.createPokemon(levelName);
	registerTextures(pokemonManger.passTextures());

	hudManager.createHud();
	for (std::string& texture : playerManager.getItems())
	{
		hudManager.addItem(texture);
	}
	registerTextures(hudManager.passTextures());

	scene->addGraphics(levelName);
	registerTextures(scene->passTextures(levelName));
	registerAudio(scene->passBeats());

	eqManager.createEquipment(levelName);
	registerTextures(eqManager.passTextures());

	registerBehaviourObjects();
	engineFacade->createCamera(playerManager.player->transform.position.x, playerManager.player->transform.position.y);
}

void GameManager::staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	((GameManager*)p)->passCollisionCheck(collider, x, y, direction);
}

void GameManager::passCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction)
{
	engineFacade->passCollisionCheck(collider, x, y, direction);
}

void GameManager::staticCameraCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->passPlayerPosition(x, y);
}

void GameManager::passPlayerPosition(int x, int y)
{
	engineFacade->passPlayerPosition(x, y);
}

void GameManager::staticInteractCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->interactCallbackFunction(x, y);
}

void GameManager::interactCallbackFunction(int x, int y)
{
	engineFacade->passInteract(x, y);
}

void GameManager::staticGameOverbackFunction(void* p)
{
	((GameManager*)p)->gameOverCallbackFunction();
}

void GameManager::gameOverCallbackFunction()
{
	engineFacade->gameOver();
}

void GameManager::staticUpdateHUDHealthCallbackFunction(void* p, bool hit)
{
	((GameManager*)p)->updateHUDHealthCallbackFunction(hit);
}

void GameManager::updateHUDHealthCallbackFunction(bool hit)
{
	hudManager.updateHUDHealth(hit);
}

void GameManager::staticLoadNextLevelCallbackFunction(void* p)
{
	((GameManager*)p)->loadNextLevelCallbackFunction();
}

void GameManager::loadNextLevelCallbackFunction()
{
	currentlevel++;
	createLevel(levels[currentlevel]);
	engineFacade->loadScene(levels[currentlevel], "", true);
	//engineFacade->deleteScene(levels[currentlevel - 1]);
}