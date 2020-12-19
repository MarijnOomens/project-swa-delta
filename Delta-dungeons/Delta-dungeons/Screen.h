#pragma once

#include <string>
#include <vector>
#include "GraphicsComponent.h"
#include "SceneLoader.h"

class Screen : public GameObject
{
public:
	std::unique_ptr<GraphicsComponent> gc;
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override {}
	void update(int time) override {}
	void interact(std::shared_ptr<BehaviourObject> interactor) override {}
	void start() override {}
	void setParent() override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
};