#pragma once
#include "BehaviourObject.h"
#include <string>

class ColliderComponent : public BehaviourObject {
public:
	int x;
	int y;

	ENGINE_API ColliderComponent() {};
	ENGINE_API ~ColliderComponent() {};

	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
	//ENGINE_API bool hasCollision();
};