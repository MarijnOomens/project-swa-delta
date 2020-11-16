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
#include "XMLSceneParser.h"
#include "GraphicsComponent.h"

class Scene : public GameObject
{
public:
	Scene() {}
	Scene(int x, int y);
	~Scene() {}

	void* pointer;

	void addGraphics();
	std::map<std::string, std::string> passTextures() const;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void interact() override;

	void checkCollision(int x, int y);

private:
	int x = 0, y = 0;
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::shared_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
};