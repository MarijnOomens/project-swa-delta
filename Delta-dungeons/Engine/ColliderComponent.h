#pragma once
#include "BehaviourObject.h"
#include <string>
#include "Strategy.h"
#include "StopStrategy.h"

typedef void(*cbCollision) (void*, std::shared_ptr<ColliderComponent>, int, int, KeyCodes);

class ColliderComponent : public BehaviourObject {
public:
	std::string tag;
	cbCollision collisionFunc;
	void* pointer;
	bool isTrigger = false;
	std::shared_ptr<Strategy> strategy = nullptr;

	ENGINE_API ColliderComponent();
	ENGINE_API ColliderComponent(cbCollision f, void* p);
	ENGINE_API ~ColliderComponent() {};

	ENGINE_API void actCollision(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction);
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
	ENGINE_API void setStrategy(std::shared_ptr<Strategy> strategy);
};