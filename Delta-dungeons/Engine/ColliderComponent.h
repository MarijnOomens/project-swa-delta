#pragma once
#include "BehaviourObject.h"
#include <string>

typedef void(*cbCollision) (void*, std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down);

class ColliderComponent : public BehaviourObject {
public:
	std::string tag;
	cbCollision collisionFunc;
	void* pointer;
	bool isTrigger = false;

	ENGINE_API ColliderComponent();
	ENGINE_API ~ColliderComponent() {}

	ENGINE_API virtual void actCollision(std::shared_ptr<BehaviourObject> right, std::shared_ptr<BehaviourObject> left, std::shared_ptr<BehaviourObject> up, std::shared_ptr<BehaviourObject> down);
	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
};