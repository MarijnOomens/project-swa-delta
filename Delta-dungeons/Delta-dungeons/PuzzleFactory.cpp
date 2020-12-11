#include "PuzzleFactory.h"

void PuzzleFactory::createPuzzle(std::string levelName, cbInteract interactCB, cbCollision collisionCB, void* p)
{
	//create puzzle1
	puzzleOne = std::make_shared<Puzzle>();
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> parsedPuzzleTiles
		= parser->getPuzzleData("Assets/Map/" + levelName + "/level.xml");

	//interactive puzzle tile id's are unique for puzzle one
	for (auto parsedTile : parsedPuzzleTiles)
	{
		if (std::stoi(parsedTile->tileId) == 17) 
		{
			puzzleOne->createBoulder(parsedTile, collisionCB, interactCB, p);
		}
		else if (std::stoi(parsedTile->tileId) == 16)
		{
			puzzleOne->createTrigger(parsedTile);
		}
		else if (std::stoi(parsedTile->tileId) == 18)
		{
			puzzleOne->createDoor(parsedTile);
		}
	}

	puzzleTwo = std::make_shared<Puzzle>();
	for (auto parsedTile : parsedPuzzleTiles)
	{
		if (std::stoi(parsedTile->tileId) == 12)
		{
			puzzleTwo->addToTriggerOrder(parsedTile, 0);
		}
		else if (std::stoi(parsedTile->tileId) == 13)
		{
			puzzleTwo->addToTriggerOrder(parsedTile, 1);
		}
		else if (std::stoi(parsedTile->tileId) == 14)
		{
			puzzleTwo->addToTriggerOrder(parsedTile, 2);
		}
		else if (std::stoi(parsedTile->tileId) == 15)
		{
			puzzleTwo->addToTriggerOrder(parsedTile, 3);
		}
		else if (std::stoi(parsedTile->tileId) == 20)
		{
			puzzleTwo->createDoor(parsedTile);
		}
	}
}

std::map<std::string, std::string> PuzzleFactory::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& puzzle : puzzleOne->allPuzzleObjects)
	{
		for (auto& t : puzzle.second->textures)
		{
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}
