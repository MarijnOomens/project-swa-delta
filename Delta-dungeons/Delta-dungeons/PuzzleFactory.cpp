#include "PuzzleFactory.h"

PuzzleFactory::PuzzleFactory()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void PuzzleFactory::createPuzzle(std::string levelName, cbInteract interactCB, cbCollision collisionCB, void* p)
{
	puzzleObjects.clear();

	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> puzzleData = parser->getPuzzleData("Assets/Map/" + levelName + "/level.xml");

	//interactive puzzle tile id's are unique for puzzle one
	for (auto parsedPuzzle : puzzleData)
	{
		if (std::stoi(parsedPuzzle->tileId) == 17)
		{	
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1", 
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "boulder", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 16)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "boulder_button", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 18)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "door", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 12)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "order_button", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 13)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "order_button", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 14)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "order_button", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 15)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "order_button", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
		else if (std::stoi(parsedPuzzle->tileId) == 20)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedPuzzle->x), std::stoi(parsedPuzzle->y), "door", levelName, collisionCB, interactCB, p, std::stoi(parsedPuzzle->tileId))));
		}
	}

	puzzle = std::make_shared<Puzzle>(puzzleObjects);

	// ^^opsplitsen in functies, createPuzzle1, createPuzzle2
}

std::map<std::string, std::string> PuzzleFactory::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& object : puzzleObjects)
	{
		for (auto& t : object.second->textures)
		{
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	return totalTextures;
}