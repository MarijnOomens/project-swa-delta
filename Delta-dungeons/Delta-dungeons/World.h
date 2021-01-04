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
#include "AudioUtilities.h"
#include "GameState.h"

class World : public GameObject
{
public:
	World() {}
	World(int x, int y);

	void addGraphics(const std::string& levelName);
	std::map<std::string, std::string> passTextures(std::string levelName) const;
	std::map<std::string, std::string> passBeats() const;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update(int time) override;
	void start() override;
	void setParent() override {}
	void interact(std::shared_ptr<BehaviourObject> interactor) override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}

private:
	std::string levelName;
	int x = 0, y = 0;
	std::vector<std::shared_ptr<Tile>> tileMap;
	std::shared_ptr<TextComponent> fpsText;
	std::stringstream fpsString;
	std::map<std::string, std::string> beats;
};