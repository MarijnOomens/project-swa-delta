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

	NPCManager();
	~NPCManager();

	std::shared_ptr<GameObjectBuilder> builder;
	std::map<std::string, std::shared_ptr<InteractiveObject>> npcs;

	void createNPC();
	std::map<std::string, std::string> passTextures() const;

	void addPokemon();
	std::string getRandomPokemon();
	void addTrainers();
	std::string getRandomNPC();
};