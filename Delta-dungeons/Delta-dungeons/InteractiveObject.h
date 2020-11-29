#pragma once

#include "GameObject.h"
#include "CollidingComponent.h"
#include <map>

class InteractiveObject : public GameObject
{
public:
	std::map<std::string, std::string> textures;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;
	void interact(std::shared_ptr<BehaviourObject> player) override;
	virtual void registerCollision(int x, int y, bool isDamaged, bool isTransitioned) = 0;
	std::shared_ptr<CollidingComponent> cc;
private:
	std::string name;
	std::string dialogue;
};