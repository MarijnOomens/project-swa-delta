#pragma once
#include "BehaviourObject.h"
#include <string>

typedef void(*cbCollision) (void*, int x, int y, std::string tag);

class ColliderComponent : public BehaviourObject {
public:
	std::string tag;
	cbCollision collisionFunc;
	void* pointer;
	bool isTrigger = false;

	ENGINE_API ColliderComponent();
	ENGINE_API ColliderComponent(cbCollision f, void* p);
	ENGINE_API ~ColliderComponent() {}

	ENGINE_API void actCollision(int x, int y, std::string tag);
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
};