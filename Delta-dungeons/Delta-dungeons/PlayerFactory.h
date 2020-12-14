#pragma once

#include "Player.h"
#include "XMLSceneParser.h"
#include <iostream>
#include <string>
#include "GameObjectFactory.h"

typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int, int);
typedef void(*cbGameOver) (void*);
typedef void(*cbHUD) (void*, int, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbNextLevel) (void*);

class PlayerFactory
{
public:
	std::shared_ptr<Player> player;

	PlayerFactory() {}

	void createPlayer(const std::string& levelName, cbCollision collisionCB, cbThrowCollision throwCB, cbNextLevel nextLevelCb, cbCamera cb, cbInteract interactCB, cbGameOver gameOverCB, cbHUD hudCB, void* p, void* gm);

	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
	std::vector<std::string> getItems();
};