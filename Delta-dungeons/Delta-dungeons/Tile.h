#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>

class Tile : public GameObject {
public:
	Tile(int x, int y, int xImage);
	Tile(int x, int y, int xImage, int yImage);
	~Tile() {}

	void addGraphicsComponent(std::string &imageName);
	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;

private:
	Vector2D imageCoordinates;
	std::shared_ptr<GraphicsComponent> gc;
};