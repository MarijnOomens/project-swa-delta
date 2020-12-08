#pragma once
#include "XMLSceneParser.h"
#include "Puzzle.h"
class PuzzleManager
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boundaries;
	std::vector<std::shared_ptr<Puzzle>> puzzles;
	//std::vector<std::shared_ptr<ParserData>> parsedPuzzles;

	//voor meerdere levels dezelfde parser gebruiken
	//vector puzzle.cpp

	PuzzleManager() {}
	~PuzzleManager() {}
	
	void createPuzzle(std::string levelName);
	void createBoundaries(std::string levelName);


	std::map<std::string, std::string> passTextures() const;
private:
};

