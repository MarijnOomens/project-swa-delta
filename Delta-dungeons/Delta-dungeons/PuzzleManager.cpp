#include "PuzzleManager.h"

void PuzzleManager::createPuzzle(std::string levelName)
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
			puzzle->createBoulder(parsedTile);
		}
			//puzzles->at(0)->puzzles->createPuzzleTile(parsedTile);
		//elseif
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

//getparser voor alle puzzelstukken en pas logica toe voor boundaries
	//all puzzle parserdata

//getParser checktiles within boundaries
	//




//checkpuzzlecollision
//pushstrategy
	// if nullptry (set)