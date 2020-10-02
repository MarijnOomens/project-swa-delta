#pragma once
#include "GameObject.h"
#include <list>
#include <iostream>

class Scene {
public: 
	Scene();
	Scene(std::list<GameObject> gameObjects);

private:
	std::list<GameObject> gameObjects;
	GameObject tileMap; //idk how to make the 2d array
};