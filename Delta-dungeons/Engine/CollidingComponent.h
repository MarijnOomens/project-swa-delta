#pragma once
#include "BehaviourObject.h"
#include <string>
#include <memory>
#include <iostream>
#include "CollisionStrategy.h"

class CollidingComponent : public BehaviourObject {
public:
	std::string tag;
	bool isTrigger = false;
	std::shared_ptr<CollisionStrategy> strategy;
	std::shared_ptr<BehaviourObject> parent;
	ENGINE_API CollidingComponent();
	ENGINE_API CollidingComponent(std::shared_ptr<CollisionStrategy> strategy);
	ENGINE_API ~CollidingComponent();

	ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction);
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact(std::shared_ptr<BehaviourObject> interactor) override;
	ENGINE_API void update(int time) override;
	ENGINE_API void setParent() override;
	ENGINE_API void start() override;
	ENGINE_API void setStrategy(std::shared_ptr<CollisionStrategy> strategy);
};
