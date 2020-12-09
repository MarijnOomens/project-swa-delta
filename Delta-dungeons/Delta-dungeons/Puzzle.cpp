#include "Puzzle.h"

void Puzzle::createBoulder(std::shared_ptr<ParserData> parser, cbCollision cbC, cbInteract cbI, void* gP)
{
	std::shared_ptr<BoulderPuzzleObject> boulder = 
		std::make_shared<BoulderPuzzleObject>(cbI, cbC, gP, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	boulder->setParent();
	boulder->textures.try_emplace("boulder", "Assets/Equipment/pokeball.png");
	boulders.emplace("boulder" + parser->x + parser->y, boulder);
}

void Puzzle::createTrigger(std::shared_ptr<ParserData> parser)
{
	std::shared_ptr<TriggerPuzzleObject> trigger =
		std::make_shared<TriggerPuzzleObject>(staticTriggerCallbackFunction, this, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	trigger->setParent();
	trigger->textures.try_emplace("trigger", "Assets/Equipment/pokeball.png");
	boulders.emplace("trigger" + parser->x + parser->y, trigger);
}


void Puzzle::staticTriggerCallbackFunction(void* p, int x, int y)
{
	((Puzzle*)p)->trigger(x, y);
}

void Puzzle::trigger(int x, int y)
{
	std::cout << "trigger" << std::endl;
}
