
#include "PlayerManager.h"

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

std::string PlayerManager::passTexture()
{
    std::string texture;
    

    std::map<std::string, std::string> totalTextures;
    for (auto& sprite : sprites) {
        for (auto& t : sprite.second.get()->textures) {
            totalTextures.try_emplace(t.first, t.second);
        }
    }
    return totalTextures;
}

std::shared_ptr<Player> PlayerManager::getPlayerObject()
{
    return player;
}