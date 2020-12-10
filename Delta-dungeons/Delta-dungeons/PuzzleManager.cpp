#include "PuzzleManager.h"

void PuzzleManager::createPuzzle(std::string levelName, cbInteract interactCB, cbCollision collisionCB, void* p)
{
	//create puzzle1
	puzzle = std::make_shared<Puzzle>();
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> parsedPuzzleTiles
		= parser->getPuzzleData("Assets/Map/" + levelName + "/level.xml");

	//interactive puzzle tile id's are unique for one puzzlelevel
	for (auto parsedTile : parsedPuzzleTiles)
	{
		if (std::stoi(parsedTile->tileId) == 17) 
		{
			puzzle->createBoulder(parsedTile, collisionCB, interactCB, p);
		}
		else if (std::stoi(parsedTile->tileId) == 16)
		{
			puzzle->createTrigger(parsedTile);
		}
		else if (std::stoi(parsedTile->tileId) == 18)
		{
			puzzle->createDoor(parsedTile);
		}
	}
	//create puzzle 2
}

std::map<std::string, std::string> PuzzleManager::passTextures() const
{
	std::map<std::string, std::string> totalTextures;
	for (auto& puzzle : puzzle->boulders)
	{
		for (auto& t : puzzle.second->textures)
		{
			totalTextures.try_emplace(t.first, t.second);
		}
	}
	//for (auto& puzzleTrigger : puzzle->triggers)
	//{
	//	for (auto& trigger : puzzleTrigger.second->textures)
	//	{
	//		totalTextures.try_emplace(trigger.first, trigger.second);
	//	}
	//}
	//for (auto& puzzleTrigger : puzzle->doors)
	//{
	//	for (auto& trigger : puzzleTrigger.second->textures)
	//	{
	//		totalTextures.try_emplace(trigger.first, trigger.second);
	//	}
	//}
	return totalTextures;
}

//void PuzzleManager::createPuzzles(std::string levelName)
//{
//	//create puzzle1
//	puzzles.push_back(std::make_shared<Puzzle>());
//	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
//	std::vector<std::shared_ptr<ParserData>> puzzleBoundTiles = parser->getPuzzleBoundData("Assets/Map/" + levelName + "/level.xml");
//
//	//interactive puzzle tile id's are unique for one puzzlelevel
//	for (auto parsedTile : puzzleBoundTiles)
//	{
//		//if parsedTile->id == 18, 
//			//puzzles->at(0)->puzzles->createPuzzleTile(parsedTile);
//		//elseif
//	}
//
//	//create puzzle 2
//}

//filteren van tileid 17 18
	//aka filtered parserdata
