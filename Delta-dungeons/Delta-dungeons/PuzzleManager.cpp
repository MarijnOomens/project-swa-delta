#include "PuzzleManager.h"

void PuzzleManager::createBoundaries(std::string levelName)
{
	//pokemon.clear();
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
}

void PuzzleManager::createPuzzle(std::string levelName)
{

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