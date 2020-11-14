#pragma once

#include "Player.h"
#include <iostream>
#include <string>
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbCheckCollision) (void*, int, int);
typedef void(*cbInteract) (void*, int, int);

class PlayerManager
{
public:
	std::map<std::string, std::shared_ptr<Player>> sprites;
	std::shared_ptr<Player> player;

	PlayerManager() {}
	~PlayerManager() {}

	void createPlayer(cbCamera cb, cbCheckCollision tileCB, cbInteract interactCB, void* p);
	void setCollisionToTrue();


	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
};