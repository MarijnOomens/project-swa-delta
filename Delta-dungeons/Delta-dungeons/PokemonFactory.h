#pragma once

#include <map>
#include <string>
#include <memory>
#include <ctime>
#include "IInteractiveObject.h"
#include "GameObjectBuilder.h"
#include "XMLSceneParser.h"
#include "GameObjectFactory.h"

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject> behaviourObject, int, int, KeyCodes, int);

class PokemonFactory : public GameObjectFactory
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> pokemon;
	std::vector<std::shared_ptr<PokemonParserData>> parsedPokemon;

	PokemonFactory();

	void createPokemon(const std::string& levelName, cbCollision collisionCb, void* p);
	std::map<std::string, std::string> passTextures() const;

private:
	std::shared_ptr<GameObjectBuilder> builder;
	int getRandomPokemon();
};