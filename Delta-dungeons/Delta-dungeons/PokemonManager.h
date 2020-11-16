#pragma once
#include <map>
#include <string>
#include <memory>
#include "InteractiveObject.h"
#include "GameObjectBuilder.h"
#include "XMLSceneParser.h"
class PokemonManager
{
public:
	std::map<std::string, std::shared_ptr<InteractiveObject>> pokemon;

	PokemonManager();
	~PokemonManager() {}

	void createPokemon();
	std::map<std::string, std::string> passTextures() const;

private:
	std::shared_ptr<GameObjectBuilder> builder;
};