#pragma once

#include "ParserData.h"
#include "Tile.h"
#include <array>
#include <iostream>
#include <list>
#include <vector>
#include "TextComponent.h"
#include <sstream>

class Scene : public GameObject
{
public:
	std::vector<std::shared_ptr<Tile>> tileMap;

	Scene();
	Scene(int x, int y);
	~Scene();

	void addGraphics();
	std::vector<std::shared_ptr<Tile>> makeTiles(std::vector<std::shared_ptr<ParserData>> data);
	std::map<std::string, std::string> passTextures() const;

	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
	void connectCallback() override; //Add callbackfunction
	void callbackFunction() override;
	void update() override;

private:
	int x;
	int y;
	int test = 0;
	std::shared_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
};