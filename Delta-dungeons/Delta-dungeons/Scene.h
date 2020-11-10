#pragma once

#include "ParserData.h"
#include "Tile.h"
#include <array>
#include <iostream>
#include <list>
#include <vector>
#include "TextComponent.h"
#include <sstream>
#include "DebugUtilities.h"

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

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void update() override;
	void checkCollision(int x, int y);

private:
	int x;
	int y;
	std::shared_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
};