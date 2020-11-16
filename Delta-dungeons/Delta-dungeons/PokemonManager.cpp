#include "PokemonManager.h"

PokemonManager::PokemonManager()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void PokemonManager::createPokemon()
{
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<PokemonParserData>> parsedPokemon = parser->loadPokemon("Assets/maps/level1pokemon.xml");
	int x = 768;
	int y = 640;
	
	srand(time(0));
	while (pokemon.size() < 8)
	{
		int randomPokemon = rand() % (parsedPokemon.size() -1);
		std::shared_ptr<PokemonParserData> p = parsedPokemon.at(randomPokemon);
		int random = rand() % 100;
		if (random < std::stoi(p->encounterRate))
		{
			pokemon.emplace(p->name + std::to_string(pokemon.size()), builder->getPokemon(x, y, p->name));
			x += 128;
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