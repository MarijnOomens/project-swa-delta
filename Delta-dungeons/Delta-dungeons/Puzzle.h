#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
class Puzzle
{
public:

	//voor meerdere levels dezelfde parser gebruiken
	//std::vector<std::shared_ptr<PokemonParserData>> parsedPokemon;

	//vector puzzle.cpp

	Puzzle() {}
	~Puzzle() {}

	std::vector<std::shared_ptr<IInteractiveObject>> parsedPokemon;
private:
};