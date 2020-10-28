
#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	
}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::createPlayer()
{
	std::shared_ptr<Player> player = std::make_shared<Player>();
	sprites.try_emplace("Player", player);
}

std::map<std::string, std::string> PlayerManager::passTextures()
{
    std::map<std::string, std::string> totalTextures;
    for (auto& sprite : sprites) {
        for (auto& t : sprite.second.get()->textures) {
            totalTextures.try_emplace(t.first, t.second);
        }
    }
    return totalTextures;
}