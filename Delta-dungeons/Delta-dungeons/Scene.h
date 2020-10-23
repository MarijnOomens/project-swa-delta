#pragma once
#include "Tile.h"
#include <list>
#include <iostream>
#include <array>
#include <vector>
#include "ParserData.h"

class Scene {
public: 
	Scene();
	Scene(int x, int y);
	std::list<Tile*> makeTiles(std::list<ParserData> data);

private:
	int x;
	int y;
	std::list<Tile*> tileMap;
};