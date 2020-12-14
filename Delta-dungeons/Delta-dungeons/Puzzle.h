#pragma once

#include "DoorPuzzleObject.h"
#include "OrderTriggerPuzzleObject.h"
#include "BoulderPuzzleObject.h"
#include "BoulderTriggerPuzzleObject.h"

#include <map>

class Puzzle
{
public:
	Puzzle(std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects);

	static void staticBoulderTriggerCallbackFunction(void* p);
	void checkBoulderTriggers();
	
	static void staticOrderTriggerCallbackFunction(void* p, int orderNumber);
	void orderTrigger(int orderNumber);


	void resetOrder();
	void openDoors(const std::string& puzzleName);

private:
	std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects;
};

