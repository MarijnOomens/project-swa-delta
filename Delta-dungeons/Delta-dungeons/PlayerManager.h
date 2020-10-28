#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Player.h"

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();


	std::map<std::string, std::shared_ptr<Player>> sprites;
	std::shared_ptr<Player> player;
	
	void createPlayer();
	std::shared_ptr<Player> getPlayerObject();
	std::map<std::string, std::string> passTextures() const;



};