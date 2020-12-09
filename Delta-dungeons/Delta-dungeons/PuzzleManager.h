#pragma once
#include "XMLSceneParser.h"
#include "Puzzle.h"
#include "BoulderPuzzleObject.h"
class PuzzleManager
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boundaries;
	//std::vector<std::shared_ptr<Puzzle>> puzzles;
	std::shared_ptr<Puzzle> puzzle;

	//voor meerdere levels dezelfde parser gebruiken
	//vector puzzle.cpp

	PuzzleManager() {}
	~PuzzleManager() {}
	

	void createPuzzles(std::string levelName);
	void createPuzzle(std::string levelName);


	std::map<std::string, std::string> passTextures() const;
private:
};

