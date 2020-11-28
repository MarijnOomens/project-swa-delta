#pragma once

#include <map>
#include <string>
#include <memory>
#include <ctime>
#include "InteractiveObject.h"
#include "GameObjectBuilder.h"
#include "XMLSceneParser.h"

class PokemonManager
{
public:
	std::map<std::string, std::shared_ptr<InteractiveObject>> pokemon;
	std::vector<std::shared_ptr<PokemonParserData>> parsedPokemon;

	PokemonManager();
	~PokemonManager() {}

	void createPokemon(std::string levelName);
	std::map<std::string, std::string> passTextures() const;

private:
	std::shared_ptr<GameObjectBuilder> builder;
	int getRandomPokemon();
};