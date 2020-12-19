#include "Puzzle.h"

Puzzle::Puzzle(std::multimap<std::string, std::shared_ptr<IInteractiveObject>> puzzleObjects) : puzzleObjects(puzzleObjects)
{
	setCallbacks();
}

void Puzzle::staticResetBouldersCallbackFunction(void* p)
{
	((Puzzle*)p)->resetBoulders();
}

void Puzzle::resetBoulders()
{
	bool isAllTriggered = true;
	for (auto& object : puzzleObjects)
	{
		if (object.first == "puzzle1" && dynamic_cast<BoulderPuzzleObject*>(object.second.get()) != nullptr)
		{
			dynamic_cast<BoulderPuzzleObject*>(object.second.get())->sharedFromThis->start();
		}
		else if (object.first == "puzzle1" && dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get()) != nullptr)
		{
			dynamic_cast<BoulderTriggerPuzzleObject*>(object.second.get())->sharedFromThis->start();
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
		AudioUtilities::getInstance().playEffect("gate");
		openDoors("puzzle1");
	}
}

void Puzzle::staticOrderTriggerCallbackFunction(void* p, int orderNumber)
{
	((Puzzle*)p)->orderTrigger(orderNumber);
}

void Puzzle::orderTrigger(int orderNumber)
{
	bool isOrderCorrect = true;

	for (int i = 0; i < orderNumber; i++)
	{
		if (!searchOrderTriggerPuzzle(i))
		{
			resetOrder();
			isOrderCorrect = false;
			break;
		}
	}

	if (isOrderCorrect && getOrderTriggerAmount() == orderNumber)
	{
		AudioUtilities::getInstance().playEffect("gate");
		openDoors("puzzle2");
	}
}

bool Puzzle::searchOrderTriggerPuzzle(int orderNumber)
{
	for (auto& object : this->puzzleObjects)
	{
		auto triggerObject = dynamic_cast<OrderTriggerPuzzleObject*>(object.second.get());
		if (triggerObject != nullptr && triggerObject->orderNumber == orderNumber)
		{
			return triggerObject->triggered;
		}
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
		else if (dynamic_cast<ResetPuzzleObject*>(object.second.get()) != nullptr)
		{
			auto orderTriggerObject = dynamic_cast<ResetPuzzleObject*>(object.second.get());
			orderTriggerObject->setResetTriggerCallback(staticResetBouldersCallbackFunction, this);
		}
	}
}