#include "PuzzleFactory.h"

PuzzleFactory::PuzzleFactory()
{
	builder = std::make_shared<GameObjectBuilder>();
}

void PuzzleFactory::createPuzzle(std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
	puzzleObjects.clear();

	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> puzzleData = parser->getPuzzleData("Assets/Map/" + levelName + "/level.xml");

	for (auto parsedPuzzle : puzzleData)
	{
		if (std::stoi(parsedPuzzle->tileId) == 16 || std::stoi(parsedPuzzle->tileId) == 17 || std::stoi(parsedPuzzle->tileId) == 18)
		{	
			createPuzzleOne(parsedPuzzle, levelName, interactCb, collisionCb, p);
		}
		else if (std::stoi(parsedPuzzle->tileId) == 12 || std::stoi(parsedPuzzle->tileId) == 13 || std::stoi(parsedPuzzle->tileId) == 14 || std::stoi(parsedPuzzle->tileId) == 15 || std::stoi(parsedPuzzle->tileId) == 20)
		{
			createPuzzleTwo(parsedPuzzle, levelName, interactCb, collisionCb, p);
		}
	}
	puzzle = std::make_shared<Puzzle>(puzzleObjects);
}

void PuzzleFactory::createPuzzleOne(std::shared_ptr<ParserData> parsedData, std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
	if (std::stoi(parsedData->tileId) == 16)
	{
	puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1",
		builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "boulder_button", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
	}
	else if (std::stoi(parsedData->tileId) == 17)
	{
		puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1",
			builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "boulder", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
	}
	else if (std::stoi(parsedData->tileId) == 18)
	{
		puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle1",
			builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "door", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
	}
}

void PuzzleFactory::createPuzzleTwo(std::shared_ptr<ParserData> parsedData, std::string levelName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
		if (std::stoi(parsedData->tileId) == 12)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2", 
				builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "order_button", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
		}
		else if (std::stoi(parsedData->tileId) == 13)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "order_button", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
		}
		else if (std::stoi(parsedData->tileId) == 14)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "order_button", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
		}
		else if (std::stoi(parsedData->tileId) == 15)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "order_button", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
		}
		else if (std::stoi(parsedData->tileId) == 20)
		{
			puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>("puzzle2",
				builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), "door", levelName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
		}
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