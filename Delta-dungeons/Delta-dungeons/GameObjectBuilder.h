#pragma once

#include "GameObject.h"
#include "Pokemon.h"
#include "Pokeball.h"
#include "Berry.h"
#include "RunningShoes.h"
#include "Player.h"
#include "NPC.h"
#include "Medal.h"
#include "BoulderPuzzleObject.h"
#include "BoulderTriggerPuzzleObject.h"
#include "DoorPuzzleObject.h"
#include "OrderTriggerPuzzleObject.h"
#include "ResetPuzzleObject.h"

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject> behaviourObject, int, int, KeyCodes, int);

class GameObjectBuilder 
{
public:
	GameObjectBuilder() {}
	~GameObjectBuilder() {}

	//std::shared_ptr<Player> getPlayer(int x, int y);
	std::shared_ptr<NPC> getNPC(int x, int y, std::string name, std::vector<std::string> dialogue);
	std::shared_ptr<Pokemon> getPokemon(int x, int y, const std::string& name, cbCollision collisionCb, void* p);
	std::shared_ptr<IEquipment> getEquipment(int x, int y, const std::string& name, const std::string& levelName);
	std::shared_ptr<IInteractiveObject> getPuzzle(int x, int y, const std::string& name, cbCollision collisionCB, cbInteract interactCB, void* p, int tileId);
private:
};