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

class Scene : public GameObject
{
public:

	Scene();
	Scene(int x, int y);
	~Scene();

	void addGraphics();
	std::vector<std::shared_ptr<Tile>> makeTiles(std::vector<std::shared_ptr<ParserData>> data);
	std::map<std::string, std::string> passTextures() const;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;

private:
	int x;
	int y;
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::unique_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
};