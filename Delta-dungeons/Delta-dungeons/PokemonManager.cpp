#include "PokemonManager.h"

PokemonManager::PokemonManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void PokemonManager::createPokemon()
{
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> pokemonTile = parser->getNPCDataList("Assets/Maps/Level2/level.xml");
	parsedPokemon = parser->loadPokemon("Assets/Maps/Level2/pokemon.xml");
	srand(time(0));
	for (auto parsedTile : pokemonTile)
	{
		if (parsedTile->tileId == "7") {
			std::shared_ptr<PokemonParserData> p = parsedPokemon[getRandomPokemon()];
			pokemon.emplace(p->name + std::to_string(pokemon.size()), builder->getPokemon(std::stoi(parsedTile->x), std::stoi(parsedTile->y), p->name));
		}
	}

}

std::map<std::string, std::string> PokemonManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : pokemon) {
		for (auto& t : npc.second->textures) {
			totalTextures.emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

int PokemonManager::getRandomPokemon()
{
	bool hasFound = false;
	while (!hasFound) 
	{
		int randomPokemon = rand() % (parsedPokemon.size() - 1);
		int random = rand() % 100;
		if (random < std::stoi(parsedPokemon[randomPokemon]->encounterRate))
		{
			return randomPokemon;
		}
	}
}