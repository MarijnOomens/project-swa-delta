#include "PlayerFactory.h"

/// <summary>
/// This is a manager class for the player in which the Player is created and the texture is stored.
/// </summary>
void PlayerFactory::createPlayer(const std::string& levelName, cbCollision collisionCb, cbThrowCollision throwCB, cbCamera cb, cbInteract interactCB, cbGameOver gameOverCB, cbHUD hudCB, void* p)
{
    std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
    std::shared_ptr<ParserData> positionData = parser->getPlayerPosition("Assets/Map/" + levelName + "/level.xml");
	player = std::make_shared<Player>(std::stoi(positionData->x), std::stoi(positionData->y), collisionCb, throwCB, cb, interactCB, gameOverCB, hudCB, p);
    player->setParent();
}

/// <summary>
/// This method gives all the textures back in a map.
/// </summary>
/// <returns>Returns a map of the textures.</returns>
std::map<std::string, std::string> PlayerFactory::passTextures() const
{
    std::map<std::string, std::string> texture = player->textures;
    return texture;
}

/// <summary>
/// This method gives back the playerObject as a shared_pointer.
/// </summary>
/// <returns>Returns the playerObject shared_pointer.</returns>
std::shared_ptr<Player> PlayerFactory::getPlayerObject()
{
    return player;
}

std::vector<std::string> PlayerFactory::getItems()
{
    return player->getItems();
}