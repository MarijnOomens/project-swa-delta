#include "Puzzle.h"

Puzzle::Puzzle(std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects) : puzzleObjects(puzzleObjects)
{
	setCallbacks();
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
	int max = getOrderTriggerAmount();
	int orderCounter = 0;
	bool isOrderCorrect = false;
	bool exit = false;

	while (!exit && orderNumber != 0)
	{
		for (auto& object : puzzleObjects)
		{
			if (object.first == "puzzle2", dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get()))
			{
				auto orderObject = dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get());
				if (orderCounter == orderObject->orderNumber)
				{
					if (!orderObject->triggered)
					{
						resetOrder();
						exit = true;
					}
					else
					{
						if (orderCounter == max) {
							isOrderCorrect = true;
							exit = true; 
						}
						else if (orderCounter == orderNumber)
						{
							exit = true; 
						}
						else
						{
							orderCounter++;
						}
					}
				}
			}
		}
	}

	if (isOrderCorrect && orderCounter == max)
	{
		openDoors("puzzle2");
	}
}

void Puzzle::resetOrder()
{
	for (auto& object : puzzleObjects)
	{
		if (dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get())->orderPuzzleObject->start();
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

int Puzzle::getOrderTriggerAmount()
{
	int max = -1;
	for (auto& object : puzzleObjects)
	{
		if (object.first == "puzzle2", dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get()))
		{
			max++;
		}
	}

	return max;
}

void Puzzle::setCallbacks()
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