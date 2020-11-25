#pragma once
#include "ColliderComponent.h"
#include "main.h"

class RegularColliderComponent: public ColliderComponent
{
public:
	ENGINE_API RegularColliderComponent();
	ENGINE_API RegularColliderComponent(cbCollision f, void* p);
	ENGINE_API ~RegularColliderComponent() {};

	ENGINE_API void actCollision(std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down) override;
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
};