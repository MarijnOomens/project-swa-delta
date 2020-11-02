#include "GameManager.h"

GameManager::GameManager() 
{
	engineFacade = EngineFacade();
	engineFacade.init();
	/*uiManager = UIManager();
	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());*/

	playerManager = std::make_shared<PlayerManager>();
	playerManager.get()->createPlayer(staticCameraCallbackFunction, this);
	registerTextures(playerManager.get()->passTextures());
	

	scene = Scene();	
	scene.addGraphics();
	registerTextures(scene.passTextures());
	

	registerBehaviourObjects();
	engineFacade.createCamera(playerManager.get()->player.get()->transform.position.x, playerManager.get()->player.get()->transform.position.y);
	engineFacade.startGame();
}

GameManager::~GameManager() {}

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

void GameManager::registerTextures(std::map<std::string, std::string> textures) 
{
	engineFacade.registerTextures(textures);
}

void GameManager:: staticCameraCallbackFunction(void* p, int x, int y) 
{
	((GameManager*)p)->passPlayerPosition(x, y);
}

void GameManager::passPlayerPosition(int x, int y)
{
	engineFacade.passPlayerPosition(x, y);
}