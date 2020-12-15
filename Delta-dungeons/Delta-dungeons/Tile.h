#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"
#include "TransitionStrategy.h"
#include "LevelWinStrategy.h"
#include <string>

class Tile : public GameObject {
public:
	bool isCollider = false;
	int originX;
	int originY;

	Tile(int x, int y, int xImage, bool collider, bool isTrigger, bool isWinTrigger);
	Tile(int x, int y, int xImage, int yImage, bool collider, bool isTrigger, bool isWinTrigger);

	void addGraphicsComponent(const std::string& imageName);
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void setParent() override;
	void start() override;

private:
	Vector2D imageCoordinates;
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};