#pragma once

#include "Player.h"
#include <iostream>
#include <string>

typedef void(*cbCamera) (const void*, int, int);

class PlayerManager
{
public:
	std::shared_ptr<Player> player;

	PlayerManager() {}
	~PlayerManager() {}

	void createPlayer(cbCamera cb, const void* p);

	std::map<std::string, std::string> passTextures() const;
	std::shared_ptr<Player> getPlayerObject();
	std::vector<std::string> getItems();
};