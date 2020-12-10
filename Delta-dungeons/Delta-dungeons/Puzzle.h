#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
#include "ParserData.h"
#include "BoulderPuzzleObject.h"
#include "TriggerPuzzleObject.h";

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class Puzzle
{
public:
	Puzzle() {}
	~Puzzle() {}

	//interactive objects puzzle 1: 
		//door, trigger, boulder
	std::vector<std::shared_ptr<IInteractiveObject>> doors;
	std::map<std::string, std::shared_ptr<IInteractiveObject>> boulders;
	std::map<std::string, std::shared_ptr<IInteractiveObject>> triggers;

	void createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbCollision, cbInteract cbInteract, void* gPointer);
	void createTrigger(std::shared_ptr<ParserData> parser);

	static void staticTriggerCallbackFunction(void* p);
	void trigger();
	//check in puzzle if all triggers are true
		//then call interact from door class, to open/remove collider door
private:
};