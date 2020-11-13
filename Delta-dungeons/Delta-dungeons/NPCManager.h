#pragma once
#include "NPC.h"
#include "Pokemon.h"
#include "GameObjectBuilder.h"
#include <string>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>

class NPCManager 
{
public:
	std::unique_ptr<std::vector<std::string>> pokemonList;
	std::unique_ptr<std::vector<std::string>> trainerList;
	std::map<std::string, std::shared_ptr<InteractiveObject>> npcs;

	NPCManager();
	~NPCManager() {}

	void createNPC();
	std::map<std::string, std::string> passTextures() const;

	void addPokemon();
	std::string getRandomPokemon();
	void addTrainers();
	std::string getRandomNPC();
private:
	std::shared_ptr<GameObjectBuilder> builder;
};