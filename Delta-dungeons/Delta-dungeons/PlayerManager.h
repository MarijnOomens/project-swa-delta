#pragma once

#include "Player.h"
#include <iostream>
#include <string>
typedef void(*cbCamera) (void*, int, int);
typedef void(*cbInteract) (void*, int, int);

class PlayerManager
{
public:
	std::shared_ptr<Player> player;

	PlayerManager() {}
	~PlayerManager() {}

	void createPlayer(cbCamera cb, cbInteract interactCB, void* p);

	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
	std::vector<std::string> getItems();
};