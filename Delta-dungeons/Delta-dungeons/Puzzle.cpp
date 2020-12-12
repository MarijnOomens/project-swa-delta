#include "Puzzle.h"

Puzzle::Puzzle(std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects) : puzzleObjects(puzzleObjects)
{
	for (auto& object : this->puzzleObjects)
	{
		if (dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto triggerObject = dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get());
			triggerObject->setBoulderTriggerCallback(staticBoulderTriggerCallbackFunction, this);
		}
	}
}


void Puzzle::staticBoulderTriggerCallbackFunction(void* p)
{
	((Puzzle*)p)->checkBoulderTriggers();
}

void Puzzle::checkBoulderTriggers()
{
	bool isAllTriggered = true;
	for (auto& object : puzzleObjects)
	{
		if (dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto triggerObject = dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get());
			if (!triggerObject->triggered)
			{
				isAllTriggered = false;
			}
		}
	}


	if (isAllTriggered)
	{
		openDoors();
	}
}

void Puzzle::openDoors()
{
	for (auto& object : puzzleObjects)
	{
		if (dynamic_cast<DoorPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto doorObject = dynamic_cast<DoorPuzzleObject*>(object.second.get());
			doorObject->interact(nullptr);
		}
	}
}