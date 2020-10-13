#pragma once
#include "GameObject.h"
#include <list>
#include <iostream>
#include <array>;
#include <vector>;

class Scene {
public: 
	Scene(int x, int y);

private:
	int x;
	int y;
	std::vector<std::vector<GameObject>> tileMap;
};