#include "PuzzleManager.h"

void PuzzleManager::createBoundaries(std::string levelName)
{
	//pokemon.clear();
	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> puzzleBoundTiles = parser->getPuzzleBoundData("Assets/Map/" + levelName + "/level.xml");

	//make sharedptr puzzle and move it to the puzzles vector list
	for (auto parsedTile : puzzleBoundTiles)
	{
		//acces created puzzle and call create object, assign static method of puzzle to puzzleobject.

		//if tileId == 8,
			//create gate object 
		//if tileId == 18
			//create boulder object 

		if (parsedTile->tileId == "11") 
		{
			//std::stoi(parsedTile->x)
			//std::stoi(parsedTile2->y)
			//check left and up for first tile
		}
	}
}

void PuzzleManager::createPuzzle(std::string levelName)
{
	//create puzzle1

	std::unique_ptr<XMLSceneParser> parser = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<ParserData>> puzzleBoundTiles = parser->getPuzzleBoundData("Assets/Map/" + levelName + "/level.xml");
	for (auto parsedTile : puzzleBoundTiles)
	{
		if (parsedTile->tileId == "11")
		{
			//check left and up for first tile
			bool foundLeftUp = false;
			for (auto parsedTile2 : puzzleBoundTiles)
			{
				if (std::stoi(parsedTile2->x) == std::stoi(parsedTile->x) - 1)
				{
					if (std::stoi(parsedTile2->y) == std::stoi(parsedTile->y) - 1)
					{
						foundLeftUp = false;
					}
				}
			}
			foundLeftUp = true;
			if (foundLeftUp)
			{

				//this is the first tile
			}
			parsedTile->x;
			parsedTile->y;
		}
	}
	//create puzzle 2
}

//filteren van tileid 17 18
	//aka filtered parserdata

//getparser voor alle puzzelstukken en pas logica toe voor boundaries
	//all puzzle parserdata

//getParser checktiles within boundaries
	//




//checkpuzzlecollision
//pushstrategy
	// if nullptry (set)