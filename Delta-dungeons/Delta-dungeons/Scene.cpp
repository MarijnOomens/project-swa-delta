#include "Scene.h"
#include "GraphicsComponent.h"

Scene::Scene(){}

Scene::Scene(int x, int y) : x(x), y(y) {};

Scene::~Scene() {}

std::list<Tile*> Scene::makeTiles(std::list<ParserData> data)
{
	for(ParserData tile : data)
	{
		GraphicsComponent* gc;
		int first = tile.tileId[0] -48;
		if (tile.tileId[1]) {
			int second = tile.tileId[1]- 48;
			Tile* t = new Tile(std::stoi(tile.x), std::stoi(tile.y), first, second);
			tileMap.push_back(t);
		}
		else 
		{
			Tile* t = new Tile(std::stoi(tile.x), std::stoi(tile.y), first);
			tileMap.push_back(t);
		}
	}
	return tileMap;
}