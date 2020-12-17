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

	for (auto& parsedPuzzle : puzzleData)
	{
		if (std::stoi(parsedPuzzle->tileId) == 16 || std::stoi(parsedPuzzle->tileId) == 18 || std::stoi(parsedPuzzle->tileId) == 2)
		{	
			createPuzzleOne(parsedPuzzle, "puzzle1", interactCb, collisionCb, p);
		}
		else if (std::stoi(parsedPuzzle->tileId) == 12 || std::stoi(parsedPuzzle->tileId) == 13 || std::stoi(parsedPuzzle->tileId) == 14 || std::stoi(parsedPuzzle->tileId) == 15 || std::stoi(parsedPuzzle->tileId) == 20)
		{
			createPuzzleTwo(parsedPuzzle, "puzzle2", interactCb, collisionCb, p);
		}
	}
	for (auto& parsedPuzzle : puzzleData)
	{
		if (std::stoi(parsedPuzzle->tileId) == 17)
		{
			createPuzzleOne(parsedPuzzle, "puzzle1", interactCb, collisionCb, p);
		}
	}

	if (!puzzleObjects.empty())
	{
		puzzle = std::make_shared<Puzzle>(puzzleObjects);
	}
}

void PuzzleFactory::createPuzzleOne(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
	if (std::stoi(parsedData->tileId) == 2)
	{
		createPuzzleObject(parsedData, puzzleName, "reset", interactCb, collisionCb, p);
	}
	else if (std::stoi(parsedData->tileId) == 16)
	{
		createPuzzleObject(parsedData, puzzleName, "boulder_button", interactCb, collisionCb, p);
	}
	else if (std::stoi(parsedData->tileId) == 17)
	{
		createPuzzleObject(parsedData, puzzleName, "boulder", interactCb, collisionCb, p);
	}
	else if (std::stoi(parsedData->tileId) == 18)
	{
		createPuzzleObject(parsedData, puzzleName, "door", interactCb, collisionCb, p);
	}
}

void PuzzleFactory::createPuzzleTwo(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
	if (std::stoi(parsedData->tileId) == 12 || std::stoi(parsedData->tileId) == 13 || std::stoi(parsedData->tileId) == 14 || std::stoi(parsedData->tileId) == 15)
	{
		createPuzzleObject(parsedData, puzzleName, "order_not_pressed", interactCb, collisionCb, p);
	}
	else if (std::stoi(parsedData->tileId) == 20)
	{
		createPuzzleObject(parsedData, puzzleName, "door", interactCb, collisionCb, p);
	}
}

void PuzzleFactory::createPuzzleObject(std::shared_ptr<ParserData> parsedData, const std::string& puzzleName, const std::string& objectName, cbInteract interactCb, cbCollision collisionCb, void* p)
{
	puzzleObjects.insert(std::pair<std::string, std::shared_ptr<IInteractiveObject>>(puzzleName,
		builder->getPuzzle(std::stoi(parsedData->x), std::stoi(parsedData->y), objectName, collisionCb, interactCb, p, std::stoi(parsedData->tileId))));
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
