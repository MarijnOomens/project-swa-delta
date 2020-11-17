#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "ColliderComponent.h"
#include <string>

class Tile : public GameObject {
public:
	bool isCollider = false;
	int originX;
	int originY;

	Tile(int x, int y, int xImage, bool collider);
	Tile(int x, int y, int xImage, int yImage, bool collider);
	~Tile() {}

	void addGraphicsComponent(std::string& imageName);
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void interact() override;

private:
	Vector2D imageCoordinates;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
};