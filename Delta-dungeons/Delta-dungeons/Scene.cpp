#include "Scene.h"
#include "GraphicsComponent.h"

Scene::Scene(){}

Scene::Scene(int x, int y) : x(x), y(y) {};

Scene::~Scene() {}

std::vector<std::shared_ptr<Tile>> Scene::makeTiles(std::vector<ParserData> data)
{
	for(ParserData tile : data)
	{
		int first = tile.tileId[0] -48;
		if (tile.tileId[1]) {
			int second = tile.tileId[1]- 48;
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.x), std::stoi(tile.y), first, second));
		}
		else 
		{
			tileMap.push_back(std::make_shared<Tile>(std::stoi(tile.x), std::stoi(tile.y), first));
		}
	}
	return tileMap;
}