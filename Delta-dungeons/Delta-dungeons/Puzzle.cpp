#include "Puzzle.h"


void Puzzle::createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbC, cbInteract cbI, void* gP)
{
	//move to builder 
	std::shared_ptr<BoulderPuzzleObject> boulder = 
		std::make_shared<BoulderPuzzleObject>(cbI, cbC, gP, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	boulder->setParent();
	boulder->textures.try_emplace("boulder", "Assets/Equipment/pokeball.png");
	//
	boulders.emplace("boulder" + parser->x + parser->y, boulder);
	allPuzzles.emplace("boulder" + parser->x + parser->y, boulder);
}

void Puzzle::createTrigger(std::shared_ptr<ParserData> parser)
{
	//move to builder 
	std::shared_ptr<TriggerPuzzleObject> trigger =
		std::make_shared<TriggerPuzzleObject>(staticTriggerCallbackFunction, this, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	trigger->setParent();
	trigger->textures.try_emplace("trigger", "Assets/Equipment/pokeball.png");
	//
	triggers.emplace("trigger" + parser->x + parser->y, trigger);
	allPuzzles.emplace("trigger" + parser->x + parser->y, trigger);
}

void Puzzle::createDoor(std::shared_ptr<ParserData> parser)
{
	//move to builder 
	std::shared_ptr<DoorPuzzleObject> door =
		std::make_shared<DoorPuzzleObject>(std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	door->setParent();
	door->textures.try_emplace("door", "Assets/Equipment/pokeball.png");
	//
	doors.emplace("door" + parser->x + parser->y, door);
	allPuzzles.emplace("door" + parser->x + parser->y, door);
}


void Puzzle::staticTriggerCallbackFunction(void* p)
{
	((Puzzle*)p)->trigger();
}

void Puzzle::open()
{
	for (auto door : doors)
	{
		door.second->interact(nullptr);
	}
}


void Puzzle::trigger()
{
	open();
	std::cout << "trigger" << std::endl;
}
