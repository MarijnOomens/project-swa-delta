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

	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());
	registerFonts(uiManager.passFonts());

	playerManager.createPlayer(staticCameraCallbackFunction, staticInteractCallbackFunction,staticGameOverbackFunction, this);
	registerTextures(playerManager.passTextures());

	npcManager.createNPC();
	registerTextures(npcManager.passTextures());

	hudManager.createHud();
	for (std::string& texture: playerManager.getItems())
	{
		hudManager.addItem(texture);
	}
	registerTextures(hudManager.passTextures());
	
	scene = std::make_shared<Scene>();
	scene->addGraphics();
	registerTextures(scene->passTextures());

	eqManager.createEquipment();
	registerTextures(eqManager.passTextures());

	registerBehaviourObjects();
	engineFacade->createCamera(playerManager.player->transform.position.x, playerManager.player->transform.position.y);
	engineFacade->startGame();
}

/// <summary>
/// This methods registers all BehaviourObjects from all managers into one big list within the GameManager.
/// </summary>
void GameManager::registerBehaviourObjects()
{
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

	std::vector<std::shared_ptr<BehaviourObject>> level1;
	for (auto& t : scene->getComponentsRecursive())
	{
		level1.emplace_back(t);
	}
	level1.emplace_back(scene);

	for (auto& o : npcManager.npcs)
	{
		for (auto& n : o.second->getComponentsRecursive())
		{
			level1.emplace_back(n);
		}
		level1.emplace_back(o.second.get());
	}

	for (auto& o : eqManager.equipments)
	{
		for (auto& n : o.second->getComponentsRecursive())
		{
			level1.emplace_back(n);
		}
		level1.emplace_back(o.second.get());
	}
	
	for (auto& c : playerManager.player->getComponentsRecursive())
	{
		level1.emplace_back(c);
	}
		level1.emplace_back(playerManager.player);

	for (auto& c : hudManager.hud->getComponentsRecursive())
	{
		level1.emplace_back(c);
	}
	level1.emplace_back(hudManager.hud);
	engineFacade->registerScene("Level1", level1);
	engineFacade->loadScene("MainMenu", "", true);
}

/// <summary>
/// This methods gives the engineFacade all textures to give to the engine.
/// </summary>
void GameManager::registerTextures(std::map<std::string, std::string> textures)
{
	engineFacade->registerTextures(textures);
}

void GameManager::staticCameraCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->passPlayerPosition(x, y);
}

void GameManager::passPlayerPosition(int x, int y)
{
	engineFacade->passPlayerPosition(x, y);
}

/// <summary>
/// This methods gives the engineFacade all fonts to give to the engine.
/// </summary>
void GameManager::registerFonts(std::map<std::string, std::string> fonts)
{
	engineFacade->registerFonts(fonts);
}

void GameManager::staticInteractCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->interactCallbackFunction(x, y);
}

void GameManager::interactCallbackFunction(int x, int y) 
{
	engineFacade->passInteract(x, y);
}

void GameManager::staticUpdateHUDHealthCallbackFunction(void* p, bool hit)
{
	((GameManager*)p)->updateHUDHealthCallbackFunction(hit);
}

void GameManager::updateHUDHealthCallbackFunction(bool hit)
{
	hudManager.updateHUDHealth(hit);
}

void GameManager::staticGameOverbackFunction(void* p)
{
	((GameManager*)p)->gameOverCallbackFunction();
}

void GameManager::gameOverCallbackFunction()
{
	engineFacade->gameOver();
}