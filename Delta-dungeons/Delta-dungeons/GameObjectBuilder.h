#pragma once
#include "GameObject.h"
#include "Pokemon.h"
#include "Player.h"
#include "NPC.h"

class GameObjectBuilder {
public:
	GameObjectBuilder();
	~GameObjectBuilder();

	std::shared_ptr<Pokemon> getPokemon(int x, int y, std::string name);
	//std::shared_ptr<Player> getPlayer(int x, int y);
	std::shared_ptr<NPC> getNPC(int x, int y, std::string name);
	std::shared_ptr<NPC> getEquipment(int x, int y, std::string name);

private:
};