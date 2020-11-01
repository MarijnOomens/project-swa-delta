#include "PlayerManager.h"

/// <summary>
/// This is a manager class for the player in which the Player is created and the texture is stored.
/// </summary>

PlayerManager::PlayerManager()
{
	
}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::createPlayer()
{
	player = std::make_shared<Player>();
	sprites.try_emplace("Player", player);
}

std::map<std::string, std::string> PlayerManager::passTextures() const
{
    std::map<std::string, std::string> texture = sprites.begin()->second.get()->textures;
    return texture;
}

std::shared_ptr<Player> PlayerManager::getPlayerObject()
{
    return player;
}