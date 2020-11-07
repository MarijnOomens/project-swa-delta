#include "GameManager.h"

/// <summary>
/// Inside the Gamemanager all managers in the game are managed and called when the game needs them.
/// </summary>
GameManager::GameManager()
{
	engineFacade = EngineFacade();
	engineFacade.init();
	uiManager = UIManager();

	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());
	registerFonts(uiManager.passFonts());

	playerManager = std::make_shared<PlayerManager>();
	playerManager.get()->createPlayer(staticCameraCallbackFunction, staticPlayerToTileCallbackFunction, this);
	registerTextures(playerManager.get()->passTextures());

	npcManager = NPCManager();
	npcManager.createNPC();
	registerTextures(npcManager.passTextures());
	

	scene = Scene(staticTileToPlayerCallbackFunction, this);
	scene.addGraphics();
	registerTextures(scene.passTextures());
	

	registerBehaviourObjects();
	engineFacade.createCamera(playerManager.get()->player.get()->transform.position.x, playerManager.get()->player.get()->transform.position.y);
	engineFacade.startGame();
}

GameManager::~GameManager() {}

/// <summary>
/// This methods registers all BehaviourObjects from all managers into one big list within the GameManager.
/// </summary>
void GameManager::registerBehaviourObjects()
{
	for (auto& o : uiManager.screens)
	{
		for (auto& c : o.second.get()->getComponentsRecursive())
		{
			this->objects.emplace_back(c);
		}
	}

	for (auto& t : scene.getComponentsRecursive())
	{
		this->objects.emplace_back(t);
	}

	for (auto& o : npcManager.npcs)
	{
		for (auto& n : o.second.get()->getComponentsRecursive())
		{
			this->objects.emplace_back(n);
		}
		this->objects.emplace_back(o.second.get());
	}
	
	for (auto& o : playerManager.get()->sprites)
	{
		for (auto& c : o.second.get()->getComponentsRecursive())
		{
			this->objects.emplace_back(c);
		}
	}

	this->objects.emplace_back(playerManager.get()->getPlayerObject());



	engineFacade.registerBehaviourObjects(objects);
}

/// <summary>
/// This methods gives the engineFacade all textures to give to the engine.
/// </summary>
void GameManager::registerTextures(std::map<std::string, std::string> textures)
{
	engineFacade.registerTextures(textures);
}

void GameManager::staticCameraCallbackFunction(void* p, int x, int y) 
{
	((GameManager*)p)->passPlayerPosition(x, y);
}

void GameManager::passPlayerPosition(int x, int y)
{
	engineFacade.passPlayerPosition(x, y);
}
/// <summary>
/// This methods gives the engineFacade all fonts to give to the engine.
/// </summary>
void GameManager::registerFonts(std::map<std::string, std::string> fonts)
{
	engineFacade.registerFonts(fonts);
}

void GameManager::staticTileToPlayerCallbackFunction(void* p) {
	((GameManager*)p)->tileToPlayerCallbackFunction();
}

void GameManager::tileToPlayerCallbackFunction() {
	playerManager.get()->setCollisionToTrue();
}

void GameManager::staticPlayerToTileCallbackFunction(void* p, int x, int y)
{
	((GameManager*)p)->playerToTileCallbackFunction(x, y);
}

void GameManager::playerToTileCallbackFunction(int x, int y) {
	scene.checkCollision(x, y);
}
