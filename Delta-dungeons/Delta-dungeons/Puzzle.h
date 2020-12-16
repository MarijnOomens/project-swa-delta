#pragma once

#include "DoorPuzzleObject.h"
#include "OrderTriggerPuzzleObject.h"
#include "BoulderPuzzleObject.h"
#include "BoulderTriggerPuzzleObject.h"
#include "ResetPuzzleObject.h"

#include <map>

class Puzzle
{
public:
	Puzzle(std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects);

	static void staticResetBouldersCallbackFunction(void* p);
	void resetBoulders();

	static void staticBoulderTriggerCallbackFunction(void* p);
	void checkBoulderTriggers();
	
	static void staticOrderTriggerCallbackFunction(void* p, int orderNumber);
	void orderTrigger(int orderNumber);

	bool searchOrderTriggerPuzzle(int orderNumber);
	void resetOrder();
	void openDoors(const std::string& puzzleName);
	int getOrderTriggerAmount();
	void setCallbacks();

private:
	std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects;
};

