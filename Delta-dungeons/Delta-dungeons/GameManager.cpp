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

	playerManager.createPlayer(staticCameraCallbackFunction, staticPlayerToTileCallbackFunction, staticInteractCallbackFunction, this);
	registerTextures(playerManager.passTextures());

	npcManager.createNPC();
	registerTextures(npcManager.passTextures());

	scene = std::make_shared<Scene>(staticTileToPlayerCallbackFunction, this);
	scene->addGraphics(staticCollisionCallbackFunction, this);
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
		for (auto& c : o.second.get()->getComponentsRecursive())
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
		for (auto& n : o.second.get()->getComponentsRecursive())
		{
			level1.emplace_back(n);
		}
		level1.emplace_back(o.second.get());
	}

	for (auto& o : eqManager.equipments)
	{
		for (auto& n : o.second.get()->getComponentsRecursive())
		{
			level1.emplace_back(n);
		}
		level1.emplace_back(o.second.get());
	}

	for (auto& o : playerManager.sprites)
	{
		for (auto& c : o.second.get()->getComponentsRecursive())
		{
			level1.emplace_back(c);
		}
		level1.emplace_back(o.second);
	}

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
	engineFacade.get()->registerFonts(fonts);
}

void GameManager::staticTileToPlayerCallbackFunction(void* p) {
	((GameManager*)p)->tileToPlayerCallbackFunction();
}

void GameManager::tileToPlayerCallbackFunction() {
	playerManager.setCollisionToTrue();
}

void GameManager::staticCollisionCallbackFunction(void* p) {
	((GameManager*)p)->collisionCallbackFunction();
}

void GameManager::collisionCallbackFunction() {

	std::cout << count << " im alive " << std::endl;
	count++;

	//playerManager.setCollisionToTrue();
}


void GameManager::staticPlayerToTileCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->playerToTileCallbackFunction(x, y);
}

void GameManager::playerToTileCallbackFunction(int x, int y) {
	//scene.get()->checkCollision(x, y);
}

void GameManager::staticInteractCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->npcManagerCallbackFunction(x, y);
}

void GameManager::npcManagerCallbackFunction(int x, int y) {
	engineFacade.get()->passInteract(x, y);
}
