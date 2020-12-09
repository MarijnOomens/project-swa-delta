#include "Puzzle.h"

void Puzzle::createBoulder(std::shared_ptr<ParserData> parser)
{
	std::shared_ptr<BoulderPuzzleObject> boulder = 
		std::make_shared<BoulderPuzzleObject>(staticTriggerCallbackFunction, this, std::stoi(parser->x), std::stoi(parser->y), "pokeball");
	boulder->setParent();
	boulder->textures.try_emplace("boulder", "Assets/Equipment/pokeball.png");
	boulders.emplace("boulder" + parser->x + parser->y, boulder);
}

void Puzzle::staticTriggerCallbackFunction(void* p, int x, int y)
{
	((Puzzle*)p)->trigger(x, y);
}

void Puzzle::trigger(int x, int y)
{
	std::cout << "trigger" << std::endl;
}
