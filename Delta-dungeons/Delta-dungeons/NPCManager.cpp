#include "NPCManager.h"
#include "XMLSceneParser.h"

NPCManager::NPCManager()
{
	builder = std::make_shared<GameObjectBuilder>();
	pokemonList = std::make_unique<std::vector<std::string>>();
	trainerList = std::make_unique<std::vector<std::string>>();
	addPokemon();
	addTrainers();
}

NPCManager::~NPCManager() {}

void NPCManager::createNPC()
{
	std::unique_ptr<XMLSceneParser> xmlSceneParser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> npcData = xmlSceneParser.get()->getNPCDataList("Assets/maps/level1.xml");
	srand(time(0));
	for (auto parsedNPC : npcData)
	{
		if (parsedNPC.get()->tileId == "1") {
			std::string trainer = getRandomNPC();
			npcs.try_emplace(trainer + parsedNPC.get()->x + parsedNPC.get()->y, builder.get()->getNPC(std::stoi(parsedNPC.get()->x), std::stoi(parsedNPC.get()->y), trainer));
		}
		else if (parsedNPC.get()->tileId == "7") {
			std::string pokemon = getRandomPokemon();
			npcs.try_emplace(pokemon + parsedNPC.get()->x + parsedNPC.get()->y, builder.get()->getPokemon(std::stoi(parsedNPC.get()->x), std::stoi(parsedNPC.get()->y), pokemon));
		}
	}
}

std::map<std::string, std::string> NPCManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : npcs) {
		for (auto& t : npc.second->textures) {
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

void NPCManager::addPokemon()
{
	pokemonList.get()->push_back("eevee");
	pokemonList.get()->push_back("flareon");
	pokemonList.get()->push_back("vaporeon");
	pokemonList.get()->push_back("jolteon");
	pokemonList.get()->push_back("espeon");
	pokemonList.get()->push_back("umbreon");
	pokemonList.get()->push_back("leafeon");
	pokemonList.get()->push_back("glaceon");
	pokemonList.get()->push_back("sylveon");
}

std::string NPCManager::getRandomPokemon()
{
	int randomPokemon = rand() % pokemonList.get()->size();
	return pokemonList.get()->at(randomPokemon);
}

void NPCManager::addTrainers()
{
	trainerList.get()->push_back("bugtrainer");
	trainerList.get()->push_back("youngster");
	trainerList.get()->push_back("bugtrainer");
	trainerList.get()->push_back("youngster");
	trainerList.get()->push_back("bugtrainer");
	trainerList.get()->push_back("youngster");
}

std::string NPCManager::getRandomNPC()
{
	int randomTrainer = rand() % trainerList.get()->size();
	return trainerList.get()->at(randomTrainer);
}