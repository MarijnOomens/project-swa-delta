#pragma once
#include "BehaviourObject.h"
#include <string>

typedef void(*cbCollision) (void*, int, int, int, int, std::string, std::string, std::string, std::string);

class ColliderComponent : public BehaviourObject {
public:
	std::string tag;
	cbCollision collisionFunc;
	void* pointer;
	bool isTrigger = false;

	ENGINE_API ColliderComponent();
	ENGINE_API ColliderComponent(cbCollision f, void* p);
	ENGINE_API ~ColliderComponent() {}

	ENGINE_API void actCollision(int right, int left, int up, int down, std::string rightTag, std::string leftTag, std::string upTag, std::string downTag);
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
};