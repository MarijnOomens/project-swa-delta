#pragma once
#include "BehaviourObject.h"
#include <string>

typedef void(*cbCollision) (void*);

class ColliderComponent : public BehaviourObject {
public:
	int x;
	int y;
	std::string tag; //tile, equipment, npc
	cbCollision collisionFunc;
	void* pointer;

	//func(pointer, tag)
	ENGINE_API ColliderComponent() {}
	ENGINE_API ColliderComponent(const cbCollision f, void* p);
	ENGINE_API ~ColliderComponent() {}
	ENGINE_API void actCollision(std::shared_ptr<ColliderComponent> collider2);

	ENGINE_API void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	ENGINE_API void interact() override;
	ENGINE_API void update() override;
	//ENGINE_API bool hasCollision();
};