#pragma once
#include <vector>
#include <memory>
#include "PuzzleObject.h"
#include "ParserData.h"
#include "BoulderTriggerPuzzleObject.h"
#include "OrderTriggerPuzzleObject.h"
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
	std::map<std::string, std::shared_ptr<BoulderTriggerPuzzleObject>> boulderTriggers;

	std::vector<std::shared_ptr<OrderTriggerPuzzleObject>> orderTriggers;

	//om te voorkomen dat gamemanager voor iedere unieke map moet registreren
	std::map<std::string, std::shared_ptr<IInteractiveObject>> allPuzzleObjects;


	void createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbCollision, cbInteract cbInteract, void* gPointer);
	void createTrigger(std::shared_ptr<ParserData> parser);
	void createDoor(std::shared_ptr<ParserData> parser);
	void addToTriggerOrder(std::shared_ptr<ParserData> parser, int orderNumber);
	void resetOrder();
	void open();

	static void staticOrderTriggerCallbackFunction(void* p, int orderNumber);
	void orderTrigger(int orderNumber);

	static void staticBoulderTriggerCallbackFunction(void* p);
	void boulderTrigger();
	//check in puzzle if all triggers are true
		//then call interact from door class, to open/remove collider door
private:
};