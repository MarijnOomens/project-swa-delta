#pragma once
#include "XMLSceneParser.h"

class PuzzleManager
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boundaries;

	//voor meerdere levels dezelfde parser gebruiken
	//std::vector<std::shared_ptr<PokemonParserData>> parsedPokemon;

	PuzzleManager() {}
	~PuzzleManager() {}
	
	void createPuzzle(std::string levelName);
	void createBoundaries(std::string levelName);


	std::map<std::string, std::string> passTextures() const;
private:
};

