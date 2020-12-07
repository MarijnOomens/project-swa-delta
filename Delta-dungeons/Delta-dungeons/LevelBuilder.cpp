#include "LevelBuilder.h"

LevelBuilder::LevelBuilder(const std::string& ln, std::shared_ptr<EngineFacade> ef) : levelName(ln), engineFacade(ef) {}

void LevelBuilder::reset()
{
	scene = LevelScene();
}

Vector2D LevelBuilder::setPlayer()
{
	playerManager.createPlayer(levelName, staticCheckCollisionCallbackFunction, staticThrowCollisionCallbackFunction, staticCameraCallbackFunction, staticInteractCallbackFunction, staticGameOverbackFunction, staticUpdateHUDCallbackFunction, this);
	behaviourObjects.emplace_back(playerManager.getPlayerObject());
	for (auto& t : playerManager.getPlayerObject()->textures)
	{
		scene.setTexture(t.first, t.second);
	}
	return playerManager.getPlayerObject()->transform.position;
}

void LevelBuilder::setNPCs()
{
	npcManager.createNPC(levelName);
	for (auto& npc : npcManager.npcs)
	{
		behaviourObjects.emplace_back(npc.second);
	}
	for (auto& t : npcManager.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
}

void LevelBuilder::setPokemon()
{
	pokemonManager.createPokemon(levelName);
	for (auto& p : pokemonManager.pokemon)
	{
		behaviourObjects.emplace_back(p.second);
	}
	for (auto& t : pokemonManager.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
}

void LevelBuilder::setHud()
{
	hudManager.createHud(playerManager.getPlayerObject()->maxHealth, playerManager.getPlayerObject()->health, playerManager.getPlayerObject()->amountOfBerries, playerManager.getPlayerObject()->amountOfPokeballs);
	behaviourObjects.emplace_back(hudManager.hud);
	for (auto& t : hudManager.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& f : hudManager.passFonts())
	{
		scene.setTexture(f.first, f.second);
	}
}

void LevelBuilder::setWorld()
{
	world = std::make_shared<World>();
	world->addGraphics(levelName);
	behaviourObjects.emplace_back(world);
	for (auto& t : world->passTextures(levelName))
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& b : world->passBeats())
	{
		scene.setBeat(b.first, b.second);
	}
}

void LevelBuilder::setEquipment()
{
	eqManager.createEquipment(levelName);
	for (auto& t : eqManager.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& bo : eqManager.equipments)
	{
		behaviourObjects.emplace_back(bo.second);
	}
}

Scene LevelBuilder::getResult()
{
	scene.name = levelName;
	scene.setBehaviourObjects(behaviourObjects);
	return scene;
}

void LevelBuilder::staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	((LevelBuilder*)p)->passCollisionCheck(collider, x, y, direction, w);
}

void LevelBuilder::passCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	engineFacade->passCollisionCheck(collider, x, y, direction, w);
}

void LevelBuilder::staticThrowCollisionCallbackFunction(void* p, std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	((LevelBuilder*)p)->throwCollisionCheck(collider, x, y, direction, w);
}

void LevelBuilder::throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	engineFacade->throwCollisionCheck(collider, x, y, direction, w);
}

void LevelBuilder::staticCameraCallbackFunction(void* p, int x, int y)
{
	((LevelBuilder*)p)->passPlayerPosition(x, y);
}

void LevelBuilder::passPlayerPosition(int x, int y)
{
	engineFacade->passPlayerPosition(x, y);
}

void LevelBuilder::staticInteractCallbackFunction(void* p, std::shared_ptr<BehaviourObject> interactor, int x, int y)
{
	((LevelBuilder*)p)->interactCallbackFunction(interactor, x, y);
}

void LevelBuilder::interactCallbackFunction(std::shared_ptr<BehaviourObject> interactor, int x, int y)
{
	engineFacade->passInteract(interactor, x, y);
}

void LevelBuilder::staticGameOverbackFunction(void* p)
{
	((LevelBuilder*)p)->gameOverCallbackFunction();
}

void LevelBuilder::gameOverCallbackFunction()
{
	engineFacade->gameOver();
}

void LevelBuilder::staticUpdateHUDCallbackFunction(void* p, int health, int berries, int pokeballs)
{
	((LevelBuilder*)p)->updateHUDCallbackFunction(health, berries, pokeballs);
}

void LevelBuilder::updateHUDCallbackFunction(int health, int berries, int pokeballs)
{
	hudManager.updateHUD(health, berries, pokeballs);
}
