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
		else if (dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto orderTriggerObject = dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get());
			orderTriggerObject->setOrderTriggerCallback(staticOrderTriggerCallbackFunction, this);
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
			if (!dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get())->triggered)
			{
				isAllTriggered = false;
			}
		}
	}


	if (isAllTriggered)
	{
		openDoors("puzzle1");
	}
}

void Puzzle::staticOrderTriggerCallbackFunction(void* p, int orderNumber)
{
	((Puzzle*)p)->orderTrigger(orderNumber);
}

void Puzzle::orderTrigger(int orderNumber)
{
	int orderCounter = 0;
	bool isOrderCorrect = true;

	while (isOrderCorrect)
	{
		for (auto& object : puzzleObjects)
		{
			if (dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get()))
			{
				auto orderObject = dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get());
				if (orderCounter == orderObject->orderNumber)
				{
					if (orderObject->triggered)
					{
						orderCounter++;
					}
					else
					{
						resetOrder();
						isOrderCorrect = false;
						orderCounter = orderNumber + 1;
					}
				}
			}
		}
	}

	if (isOrderCorrect)
	{
		openDoors("puzzle2");
	}
}

void Puzzle::resetOrder()
{
	for (auto& object : puzzleObjects)
	{
		if (dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get())->triggered = false;
		}
	}
}


void Puzzle::openDoors(const std::string& puzzleName)
{
	for (auto& object : puzzleObjects)
	{
		if (object.first == puzzleName && dynamic_cast<DoorPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto doorObject = dynamic_cast<DoorPuzzleObject*>(object.second.get());
			doorObject->interact(nullptr);
		}
	}
}