#pragma once
#include "GameObject.h"
#include "Pokemon.h"
#include "Pokeball.h"
#include "Berry.h"
#include "RunningShoes.h"
#include "Player.h"
#include "NPC.h"

class GameObjectBuilder {
public:
	GameObjectBuilder();
	~GameObjectBuilder();

	std::shared_ptr<Pokemon> getPokemon(int x, int y, std::string name);
	//std::shared_ptr<Player> getPlayer(int x, int y);
	std::shared_ptr<NPC> getNPC(int x, int y, std::string name);
	std::shared_ptr<IEquipment> getPokeball(int x, int y, std::string name);
	std::shared_ptr<IEquipment> getBerry(int x, int y, std::string name);
	std::shared_ptr<IEquipment> getRunningShoes(int x, int y, std::string name);

private:
};