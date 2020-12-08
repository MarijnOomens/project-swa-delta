#include "PokemonFactory.h"

PokemonFactory::PokemonFactory()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void PokemonFactory::createPokemon(std::string levelName)
{
	pokemon.clear();
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> pokemonTile = parser->getNPCDataList("Assets/Map/" + levelName + "/level.xml");
	parsedPokemon = parser->loadPokemon("Assets/Map/" + levelName + "/pokemon.xml");
	srand(time(0));
	for (auto parsedTile : pokemonTile)
	{
		if (parsedTile->tileId == "7") {
			std::shared_ptr<PokemonParserData> p = parsedPokemon[getRandomPokemon()];
			pokemon.emplace(p->name + std::to_string(pokemon.size()), builder->getPokemon(std::stoi(parsedTile->x), std::stoi(parsedTile->y), p->name));
		}
	}
}

std::map<std::string, std::string> PokemonFactory::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& npc : pokemon) {
		for (auto& t : npc.second->textures) {
			totalTextures.emplace(t.first, t.second);
		}
	}
	return totalTextures;
}

int PokemonFactory::getRandomPokemon()
{
	bool hasFound = false;
	while (!hasFound) 
	{
		int randomPokemon = rand() % (parsedPokemon.size());
		int random = rand() % 100;
		if (random < std::stoi(parsedPokemon[randomPokemon]->encounterRate))
		{
			return randomPokemon;
		}
	}
}