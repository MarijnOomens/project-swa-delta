#include "GameObjectBuilder.h"

GameObjectBuilder::GameObjectBuilder() {}
GameObjectBuilder::~GameObjectBuilder() {}

std::shared_ptr<Pokemon> GameObjectBuilder::getPokemon(int x, int y, std::string name)
{
	std::shared_ptr<Pokemon> pokemon = std::make_shared<Pokemon>(x, y, name);
	pokemon->textures.try_emplace(name, "Assets/Pokemon/" + name + "_anims.png");
	return pokemon;
}

//std::shared_ptr<Player> GameObjectBuilder::getPlayer(int x, int y) {
//	/*std::shared_ptr<Player> player = std::make_shared<Player>(x, y);
//	player->textures.try_emplace("player", "Assets/player_anims.png");
//	return player;*/
//
//	//WIP
//	std::shared_ptr<Player> pokemon = std::make_shared<Player>(x, y, "eevee");
//	return pokemon;
//}

std::shared_ptr<NPC> GameObjectBuilder::getNPC(int x, int y, std::string name)
{
	std::shared_ptr<NPC> npc = std::make_shared<NPC>(x, y, name);
	npc->textures.try_emplace(name, "Assets/NPC/" + name + "_anims.png");
	return npc;
}

//std::shared_ptr<NPC> getEquipment(int x, int y, std::string tileset)
//{
//
//}