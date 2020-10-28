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
	
	void createPlayer();
	std::map<std::string, std::string> passTextures();

private:


};