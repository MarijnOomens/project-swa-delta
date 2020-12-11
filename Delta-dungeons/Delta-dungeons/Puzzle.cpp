#include "Puzzle.h"

void Puzzle::createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbC, cbInteract cbI, void* gP)
{
	std::shared_ptr<BoulderPuzzleObject> boulder = 
		std::make_shared<BoulderPuzzleObject>(cbI, cbC, gP, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	boulder->setParent();
	boulder->textures.try_emplace("boulder", "Assets/Equipment/pokeball.png");
	boulders.emplace("boulder" + parser->x + parser->y, boulder);
	allPuzzleObjects.emplace("boulder" + parser->x + parser->y, boulder);
}

void Puzzle::createTrigger(std::shared_ptr<ParserData> parser)
{
	std::shared_ptr<BoulderTriggerPuzzleObject> boulderTrigger =
		std::make_shared<BoulderTriggerPuzzleObject>(staticBoulderTriggerCallbackFunction, this, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	boulderTrigger->setParent();
	boulderTrigger->textures.try_emplace("boulder_trigger", "Assets/Equipment/pokeball.png");
	boulderTriggers.emplace("boulder_trigger" + parser->x + parser->y, boulderTrigger);
	allPuzzleObjects.emplace("boulder_trigger" + parser->x + parser->y, boulderTrigger);
}

void Puzzle::createDoor(std::shared_ptr<ParserData> parser)
{
	std::shared_ptr<DoorPuzzleObject> door =
		std::make_shared<DoorPuzzleObject>(std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	door->setParent();
	door->textures.try_emplace("door", "Assets/Equipment/pokeball.png");
	doors.emplace("door" + parser->x + parser->y, door);
	allPuzzleObjects.emplace("door" + parser->x + parser->y, door);
}

void Puzzle::addToTriggerOrder(std::shared_ptr<ParserData> parser, int orderNumber)
{
	std::shared_ptr<OrderTriggerPuzzleObject> orderTrigger = 
		std::make_shared<OrderTriggerPuzzleObject>(staticOrderTriggerCallbackFunction, this, orderNumber, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	orderTrigger->setParent();
	orderTrigger->textures.try_emplace("order_trigger", "Assets/Equipment/pokeball.png");
	orderTriggers.emplace_back(orderTrigger);
	allPuzzleObjects.emplace("order_trigger" + parser->x + parser->y, orderTrigger);
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
		if (!orderTriggers[i]->triggered)
		{
			isOrderCorrect = false;
			resetOrder();
		}
	}

	if (isOrderCorrect)
	{
		orderTriggers[orderNumber]->triggered = true;
	}

	if (orderTriggers[orderTriggers.size()-1]->triggered)
	{
		open();
	}
}

void Puzzle::staticBoulderTriggerCallbackFunction(void* p)
{
	((Puzzle*)p)->boulderTrigger();
}

void Puzzle::boulderTrigger()
{
	bool isAllTriggered = true;
	for (auto& trigger : boulderTriggers)
	{
		if (!trigger.second->triggered)
		{
			isAllTriggered = false;
		}
	}

	if (isAllTriggered)
	{
		open();
	}
}

void Puzzle::resetOrder()
{
	for (auto& orderTrigger : orderTriggers)
	{
		orderTrigger->triggered = false;
	}
}

void Puzzle::open()
{
	for (auto door : doors)
	{
		door.second->interact(nullptr);
	}
}


