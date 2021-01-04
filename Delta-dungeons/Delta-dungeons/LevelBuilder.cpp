#include "LevelBuilder.h"

LevelBuilder::LevelBuilder(const std::string& ln, std::shared_ptr<EngineFacade> ef) : levelName(ln), engineFacade(ef) {}

void LevelBuilder::reset()
{
	scene = LevelScene();
}

void LevelBuilder::setPlayer(cbNextLevel f, void* gm)
{
	playerFactory.createPlayer(levelName, staticCheckCollisionCallbackFunction, staticThrowCollisionCallbackFunction, f, staticCameraCallbackFunction, staticInteractCallbackFunction, staticGameOverbackFunction, this, gm);
	behaviourObjects.emplace_back(playerFactory.getPlayerObject());
	for (auto& t : playerFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
}

Vector2D LevelBuilder::getPlayerPosition()
{
	return playerFactory.getPlayerObject()->transform.position;
}

void LevelBuilder::setNPCs()
{
	npcFactory.createNPCs(levelName);
	for (auto& npc : npcFactory.npcs)
	{
		behaviourObjects.emplace_back(npc.second);
	}
	for (auto& t : npcFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
}

void LevelBuilder::setPokemon()
{
	pokemonFactory.createPokemon(levelName, staticCheckCollisionCallbackFunction, staticCheckInRangeCameraCallBack, staticAiCollisionCallback, this);
	for (auto& p : pokemonFactory.pokemon)
	{
		behaviourObjects.emplace_back(p.second);
	}
	for (auto& t : pokemonFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& b : pokemonFactory.passBeats())
	{
		scene.setBeat(b.first, b.second);
	}
}

void LevelBuilder::setHud()
{
	hudFactory.createHud(playerFactory.getPlayerObject()->maxHealth, playerFactory.getPlayerObject()->health, playerFactory.getPlayerObject()->amountOfBerries, playerFactory.getPlayerObject()->amountOfPokeballs);
	behaviourObjects.emplace_back(hudFactory.hud);
	for (auto& t : hudFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& f : hudFactory.passFonts())
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
	equipmentFactory.createEquipment(levelName);
	for (auto& t : equipmentFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& bo : equipmentFactory.equipments)
	{
		behaviourObjects.emplace_back(bo.second);
	}
}

void LevelBuilder::setPuzzle()
{
	puzzleFactory.createPuzzle(levelName, staticInteractCallbackFunction, staticCheckCollisionCallbackFunction, this);
	for (auto& t : puzzleFactory.passTextures())
	{
		scene.setTexture(t.first, t.second);
	}
	for (auto& bo : puzzleFactory.puzzleObjects)
	{
		behaviourObjects.emplace_back(bo.second);
	}
}

Scene LevelBuilder::getScene()
{
	scene.name = levelName;
	scene.setBehaviourObjects(behaviourObjects);
	return scene;
}

void LevelBuilder::staticCheckCollisionCallbackFunction(void* p, std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	((LevelBuilder*)p)->passCollisionCheck(collider, behaviourObject, x, y, direction, w);
}

void LevelBuilder::passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	engineFacade->passCollisionCheck(collider, behaviourObject, x, y, direction, w);
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

void LevelBuilder::staticInteractCallbackFunction(void* p, std::shared_ptr<BehaviourObject> interactor, int x, int y, int w, int h)
{
	((LevelBuilder*)p)->interactCallbackFunction(interactor, x, y, w, h);
}

void LevelBuilder::interactCallbackFunction(std::shared_ptr<BehaviourObject> interactor, int x, int y, int w, int h)
{
	engineFacade->passInteract(interactor, x, y, w, h);
}

void LevelBuilder::staticGameOverbackFunction(void* p)
{
	((LevelBuilder*)p)->gameOverCallbackFunction();
}

void LevelBuilder::gameOverCallbackFunction()
{
	engineFacade->gameOver();
}

bool LevelBuilder::staticCheckInRangeCameraCallBack(void* p, int x, int y)
{
	return ((LevelBuilder*)p)->checkInRangeCameraCallBack(x, y);
}

bool LevelBuilder::checkInRangeCameraCallBack(int x, int y)
{
	return engineFacade->checkInRangeCamera(x, y);
}


void LevelBuilder::staticAiCollisionCallback(void* p, std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	((LevelBuilder*)p)->aiCollisionCallback(collider, behaviourObject, x, y, direction, w);
}

void LevelBuilder::aiCollisionCallback(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	engineFacade->checkAiCollision(collider, behaviourObject, x, y, direction, w);
}