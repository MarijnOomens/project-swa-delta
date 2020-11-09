#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>

class Tile : public GameObject {
public:
	Vector2D imageCoordinates;
	std::shared_ptr<GraphicsComponent> gc;
	bool isCollider = false;
	int originX;
	int originY;
	
	Tile();
	Tile(int x, int y, int xImage, bool collider);
	Tile(int x, int y, int xImage, int yImage, bool collider);

	void addGraphicsComponent(std::string imageName);
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
	void callbackFunction() override;
	void connectCallback() override;
	void update() override;
};