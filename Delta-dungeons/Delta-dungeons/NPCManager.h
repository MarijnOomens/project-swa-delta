#pragma once
#include "NPC.h"
#include "Pokemon.h"
#include "GameObjectBuilder.h"
#include "XMLSceneParser.h"
#include <string>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>

class NPCManager
{
public:
	std::unique_ptr<std::vector<std::string>> trainerList;
	std::unique_ptr<std::vector<std::string>> pokemonList;
	std::map<std::string, std::shared_ptr<InteractiveObject>> npcs;

	NPCManager();
	~NPCManager() {}

	void createNPC();
	std::map<std::string, std::string> passTextures() const;

	void addTrainers();
	void addPokemon();
	std::string getRandomNPC();
	std::string getRandomPokemon();
private:
	std::shared_ptr<GameObjectBuilder> builder;
};