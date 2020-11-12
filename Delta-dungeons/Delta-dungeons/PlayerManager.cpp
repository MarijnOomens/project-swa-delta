#include "PlayerManager.h"

/// <summary>
/// This is a manager class for the player in which the Player is created and the texture is stored.
/// </summary>

void PlayerManager::createPlayer(cbCamera cb, const void* p)
{
	player = std::make_shared<Player>(cb, p);
	sprites.try_emplace("Player", player);
}

/// <summary>
/// This method gives all the textures back in a map.
/// </summary>
/// <returns>Returns a map of the textures.</returns>
std::map<std::string, std::string> PlayerManager::passTextures() const
{
    std::map<std::string, std::string> texture = sprites.begin()->second.get()->textures;
    return texture;
}

/// <summary>
/// This method gives back the playerObject as a shared_pointer.
/// </summary>
/// <returns>Returns the playerObject shared_pointer.</returns>
std::shared_ptr<Player> PlayerManager::getPlayerObject()
{
    return player;
}