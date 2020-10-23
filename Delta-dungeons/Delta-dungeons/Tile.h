#pragma once
#include "GameObject.h"
#include <string>
#include "GraphicsComponent.h"

class Tile : public GameObject {

public:

	Tile();
	Tile(int x, int y, int xImage);
	Tile(int x, int y, int xImage, int yImage);

	void addGraphicsComponent(GraphicsComponent* gc, std::string imageName);
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)override;
	void callbackFunction()override;
	void connectCallback()override;
	void update()override;

	GraphicsComponent* gc;
	Vector2D imageCoordinates;

};