#pragma once
#include "XMLSceneParser.h"
#include "Puzzle.h"
#include "BoulderPuzzleObject.h"

typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

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
	void createPuzzle(std::string levelName, cbCollision collisionCb, void* p);


	std::map<std::string, std::string> passTextures() const;
private:
};

