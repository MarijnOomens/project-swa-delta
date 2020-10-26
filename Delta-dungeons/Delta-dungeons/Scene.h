#pragma once

#include <list>
#include <iostream>
#include <array>
#include <vector>
#include "ParserData.h"
#include "Tile.h"

class Scene {
public: 
	Scene();
	Scene(int x, int y);
	~Scene();
	std::vector<std::shared_ptr<Tile>> makeTiles(std::vector<std::shared_ptr<ParserData>> data);

private:
	int x;
	int y;
	std::vector<std::shared_ptr<Tile>> tileMap;
};