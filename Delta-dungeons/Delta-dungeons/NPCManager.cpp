#include "NPCManager.h"

NPCManager::NPCManager()
{
	builder = std::make_shared<GameObjectBuilder>();
	trainerList = std::make_unique<std::vector<std::string>>();
	pokemonList = std::make_unique<std::vector<std::string>>();
	addTrainers();
	addPokemon();
}

void NPCManager::createNPC()
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> npcData = xmlSceneParser->getNPCDataList("Assets/Maps/Level1/level.xml");
	srand(time(0));
	for (auto parsedNPC : npcData)
	{
		if (parsedNPC->tileId == "1") {
			std::string trainer = getRandomNPC();
			npcs.try_emplace(trainer + parsedNPC->x + parsedNPC->y, builder->getNPC(std::stoi(parsedNPC->x), std::stoi(parsedNPC->y), trainer));
		}
		else if (parsedNPC->tileId == "7") {
			std::string pokemon = getRandomPokemon();
			npcs.try_emplace(pokemon + parsedNPC->x + parsedNPC->y, builder->getPokemon(std::stoi(parsedNPC->x), std::stoi(parsedNPC->y), pokemon));
		}
	}
}

std::map<std::string, std::string> NPCManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : npcs) {
		for (auto& t : npc.second->textures) {
			totalTextures.emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

void NPCManager::addTrainers()
{
	trainerList->push_back("bugtrainer");
	trainerList->push_back("youngster");
	trainerList->push_back("bugtrainer");
	trainerList->push_back("youngster");
	trainerList->push_back("bugtrainer");
	trainerList->push_back("youngster");
}

void NPCManager::addPokemon()
{
	pokemonList->push_back("eevee");
	pokemonList->push_back("flareon");
	pokemonList->push_back("vaporeon");
	pokemonList->push_back("jolteon");
	pokemonList->push_back("espeon");
	pokemonList->push_back("umbreon");
	pokemonList->push_back("leafeon");
	pokemonList->push_back("glaceon");
	pokemonList->push_back("sylveon");
}

std::string NPCManager::getRandomNPC()
{
	int randomTrainer = rand() % trainerList->size();
	return trainerList->at(randomTrainer);
}

std::string NPCManager::getRandomPokemon()
{
	int randomPokemon = rand() % pokemonList->size();
	return pokemonList->at(randomPokemon);
}