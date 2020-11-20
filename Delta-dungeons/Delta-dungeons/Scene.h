#pragma once

#include "ParserData.h"
#include "Tile.h"
#include "TextComponent.h"
#include "DebugUtilities.h"
#include "XMLSceneParser.h"
#include "GraphicsComponent.h"
#include <array>
#include <iostream>
#include <list>
#include <vector>
#include <sstream>

class Scene : public GameObject
{
public:
	Scene() {}
	Scene(int x, int y);
	~Scene() {}

	void addGraphics();
	std::map<std::string, std::string> passTextures() const;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void interact() override;

private:
	int x = 0, y = 0;
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::shared_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
};