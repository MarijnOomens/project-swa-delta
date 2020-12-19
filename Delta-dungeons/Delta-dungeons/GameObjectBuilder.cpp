#include "GameObjectBuilder.h"

//std::shared_ptr<Player> GameObjectBuilder::getPlayer(int x, int y) {
//	/*std::shared_ptr<Player> player = std::make_shared<Player>(x, y);
//	player->textures.try_emplace("player", "Assets/player_anims.png");
//	return player;*/
//
//	//WIP
//	std::shared_ptr<Player> pokemon = std::make_shared<Player>(x, y, "eevee");
//	return pokemon;
//}


std::shared_ptr<NPC> GameObjectBuilder::getNPC(int x, int y, std::string name, std::vector<std::string> dialogue)
{
	std::shared_ptr<NPC> npc = std::make_shared<NPC>(x, y, name, dialogue);
	npc->setParent();
	npc->textures.try_emplace(name, "Assets/NPC/" + name + "_anims.png");
	return npc;
}

std::shared_ptr<Pokemon> GameObjectBuilder::getPokemon(int x, int y, const std::string& name)
{
	std::shared_ptr<Pokemon> pokemon = std::make_shared<Pokemon>(x, y, name);
	pokemon->setParent();
	pokemon->textures.try_emplace(name, "Assets/Pokemon/" + name + "_anims.png");
	return pokemon;
}
/// <summary>
/// Creates desired Equipment Object.
/// </summary>
/// <param name="x">Correct x of equipment</param>
/// <param name="y">Correct y of equipment</param>
/// <param name="name">Name of Equipment.</param>
/// <returns>Correct Equipment object.</returns>
std::shared_ptr<IEquipment> GameObjectBuilder::getEquipment(int x, int y, const std::string& name, const std::string& levelName)
{
	if (name == "pokeball")
	{
		std::shared_ptr<Pokeball> pokeball = std::make_shared<Pokeball>(x, y, name);
		pokeball->setParent();
		return pokeball;
	}
	else if (name == "berry")
	{
		std::shared_ptr<Berry> berry = std::make_shared<Berry>(x, y, name);
		berry->setParent();
		berry->textures.try_emplace(name, "Assets/Equipment/" + name + ".png");
		return berry;
	}
	else if (name == "running_shoes")
	{
		std::shared_ptr<RunningShoes> runningShoes = std::make_shared<RunningShoes>(x, y, name);
		runningShoes->setParent();
		runningShoes->textures.try_emplace(name, "Assets/Equipment/" + name + ".png");
		return runningShoes;
	}
	else if (name == "boomerang")
	{
		std::shared_ptr<Boomerang> boomerang = std::make_shared<Boomerang>(x, y, name);
		boomerang->setParent();
		boomerang->textures.try_emplace(name, "Assets/Equipment/" + name + ".png");
		return boomerang;
	}
	else if (name == "medal")
	{
		std::shared_ptr<Medal> medal = std::make_shared<Medal>(x, y, name + levelName);
		medal->textures.try_emplace(name + levelName , "Assets/Equipment/" + name + "_" + levelName + ".png");
		return medal;
	}
}

std::shared_ptr<IInteractiveObject> GameObjectBuilder::getPuzzle(int x, int y, const std::string& name, cbCollision collisionCB, cbInteract interactCB, void* p, int tileId)
{
	std::shared_ptr<IInteractiveObject> puzzleObject;

	if (name == "boulder")
	{
		puzzleObject = std::make_shared<BoulderPuzzleObject>(interactCB, collisionCB, p, x, y, name);
	}
	else if (name == "boulder_button")
	{
		puzzleObject = std::make_shared<BoulderTriggerPuzzleObject>(x, y, name);
	}
	else if (name == "order_not_pressed")
	{
		puzzleObject = std::make_shared<OrderTriggerPuzzleObject>(x, y, name, tileId);
	}
	else if (name == "door")
	{
		puzzleObject = std::make_shared<DoorPuzzleObject>(x, y, name);
	}
	else if (name == "reset")
	{
		puzzleObject = std::make_shared<ResetPuzzleObject>(x, y, name);
	}

	puzzleObject->setParent();
	puzzleObject->textures.try_emplace(name, "Assets/Equipment/" + name + ".png");
	return puzzleObject;
}