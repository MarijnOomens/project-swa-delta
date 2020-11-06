#pragma once

#include <iostream>
#include <string>

#include "Player.h"
typedef void(*cbCamera) (void*, int, int);

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();


	std::map<std::string, std::shared_ptr<Player>> sprites;
	std::shared_ptr<Player> player;
	
	void createPlayer(cbCamera cb, void* p);

	std::shared_ptr<Player> getPlayerObject();
	std::map<std::string, std::string> passTextures() const;
};