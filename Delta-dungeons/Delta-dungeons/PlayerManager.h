#pragma once

#include "Player.h"
#include <iostream>
#include <string>
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, int, int);
typedef void(*cbGameOver) (void*);

class PlayerManager
{
public:
	std::map<std::string, std::shared_ptr<Player>> sprites;
	std::shared_ptr<Player> player;

	PlayerManager() {}
	~PlayerManager() {}

	void createPlayer(cbCamera cb, cbInteract interactCB, cbGameOver gameOverCB, void* p);

	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
};