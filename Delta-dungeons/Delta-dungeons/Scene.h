#pragma once

#include "ParserData.h"
#include "Tile.h"
#include <array>
#include <iostream>
#include <list>
#include <vector>
typedef void(*cbTileToPlayer) (void*);

class Scene : public GameObject
{
public:
	std::vector<std::shared_ptr<Tile>> tileMap;
	Scene();
	Scene(const cbTileToPlayer f, void* p);
	Scene(int x, int y);
	~Scene();
	cbTileToPlayer func;
	void* pointer;

	void addGraphics();
	std::vector<std::shared_ptr<Tile>> makeTiles(std::vector<std::shared_ptr<ParserData>> data);
	std::map<std::string, std::string> passTextures() const;

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void connectCallback() override; //Add callbackfunction
	void callbackFunction() override;
	void update() override;
	void checkCollision(int x, int y);

private:
	int x;
	int y;
	
};