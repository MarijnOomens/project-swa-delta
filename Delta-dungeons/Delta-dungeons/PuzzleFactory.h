#pragma once
#include "XMLSceneParser.h"
#include "Puzzle.h"
#include "BoulderPuzzleObject.h"

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);
typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);

class PuzzleFactory
{
public:
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boundaries;
	//std::vector<std::shared_ptr<Puzzle>> puzzles;
	std::shared_ptr<Puzzle> puzzleOne;
	std::shared_ptr<Puzzle> puzzleTwo;

	//voor meerdere levels dezelfde parser gebruiken
	//vector puzzle.cpp

	PuzzleFactory() {}
	~PuzzleFactory() {}
	

	//void createPuzzles(std::string levelName);
	void createPuzzle(std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p);


	std::map<std::string, std::string> passTextures() const;
private:
};

