#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
#include "ParserData.h"
#include "BoulderPuzzleObject.h"
#include "TriggerPuzzleObject.h"
#include "DoorPuzzleObject.h"

typedef void(*cbInteract) (void*, std::shared_ptr<BehaviourObject>, int, int);
typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class Puzzle
{
public:
	Puzzle() {}
	~Puzzle() {}

	//interactive objects puzzle 1: 
		//door, trigger, boulder
	std::map<std::string, std::shared_ptr<DoorPuzzleObject>> doors;
	std::map<std::string, std::shared_ptr<BoulderPuzzleObject>> boulders;
	std::map<std::string, std::shared_ptr<TriggerPuzzleObject>> triggers;

	//om te voorkomen dat gamemanager voor iedere unieke map moet registreren
	std::map<std::string, std::shared_ptr<IInteractiveObject>> allPuzzles;


	void createDoor(std::shared_ptr<ParserData> parser);
	void createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbCollision, cbInteract cbInteract, void* gPointer);
	void createTrigger(std::shared_ptr<ParserData> parser);
	void open();
	static void staticTriggerCallbackFunction(void* p);
	void trigger();
	//check in puzzle if all triggers are true
		//then call interact from door class, to open/remove collider door
private:
};