#include "GameManager.h"

/// <summary>
/// Inside the Gamemanager all managers in the game are managed and called when the game needs them.
/// </summary>
GameManager::GameManager()
{
	engineFacade = std::make_shared<EngineFacade>();
	engineFacade->init();
	SceneLoader::getInstance().setEngineFacade(engineFacade);

	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());
	registerFonts(uiManager.passFonts());

	playerManager = std::make_shared<PlayerManager>();
	playerManager.get()->createPlayer(staticCameraCallbackFunction, this);
	registerTextures(playerManager.get()->passTextures());

	npcManager = NPCManager();
	npcManager.createNPC();
	registerTextures(npcManager.passTextures());
	
	scene.addGraphics();
	registerTextures(scene.passTextures());*/

	registerBehaviourObjects();
	//engineFacade.createCamera(playerManager.player.get()->transform.position.x, playerManager.player.get()->transform.position.y);
	engineFacade->startGame();
}

GameManager::~GameManager() {}

/// <summary>
/// This methods registers all BehaviourObjects from all managers into one big list within the GameManager.
/// </summary>
void GameManager::registerBehaviourObjects()
{
	for (auto& o : uiManager.screens)
	{
		std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
		behaviourObjects.emplace_back(o.second);

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
			behaviourObjects.emplace_back(c);
		}

		engineFacade->registerScene(o.first, behaviourObjects);
	}

	//for (auto& t : scene.getComponentsRecursive())
	//{
	//	this->objects.emplace_back(t);
	//}
	//
	//for (auto& o : playerManager.sprites)
	//{
	//	for (auto& c : o.second.get()->getComponentsRecursive())
	//	{
	//		this->objects.emplace_back(c);
	//	}
	//}

	//this->objects.emplace_back(playerManager.getPlayerObject());


	engineFacade->loadScene("MainMenu", "", true);
}



/// <summary>
/// This methods gives the engineFacade all textures to give to the engine.
/// </summary>
void GameManager::registerTextures(std::map<std::string, std::string> textures)
{
	engineFacade->registerTextures(textures);
}

void GameManager:: staticCameraCallbackFunction(void* p, int x, int y) 
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