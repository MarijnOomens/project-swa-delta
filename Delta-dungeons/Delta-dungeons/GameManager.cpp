#include "GameManager.h"

GameManager::GameManager() 
{
	engineFacade = EngineFacade();
	engineFacade.init();
	/*uiManager = UIManager();
	uiManager.createBaseScreens();
	registerTextures(uiManager.passTextures());*/

	playerManager = PlayerManager();
	playerManager.createPlayer();
	player = playerManager.getPlayerObject();
	registerTextures(playerManager.passTextures());

	scene = Scene();	
	scene.addGraphics();
	registerTextures(scene.passTextures());


	registerBehaviourObjects();
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
	
	for (auto& o : playerManager.sprites)
	{
		for (auto& c : o.second.get()->getComponentsRecursive())
		{
			this->objects.emplace_back(c);
		}
	}

	this->objects.emplace_back(playerManager.getPlayerObject());



	engineFacade.registerBehaviourObjects(objects);
}

void GameManager::registerTextures(std::map<std::string, std::string> textures) 
{
	engineFacade.registerTextures(textures);
}
