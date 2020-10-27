#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>

class Tile : public GameObject {
public:
	Vector2D imageCoordinates;
	std::shared_ptr<GraphicsComponent> gc;

	Tile();
	Tile(int x, int y, int xImage);
	Tile(int x, int y, int xImage, int yImage);

	void addGraphicsComponent(std::shared_ptr<GraphicsComponent>& gc, std::string imageName);
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void callbackFunction() override;
	void connectCallback() override;
	void update() override;
};