#pragma once
#include "InteractiveObject.h"
#include "ColliderComponent.h"
#include <string>
#include <map>
#include <GraphicsComponent.h>

class NPC : public InteractiveObject
{
public:
	NPC(int x, int y, std::string& texture);

	void interact() override;

protected:
	std::string sfxPath;

private:
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<ColliderComponent> cc;
	const int animationSpeed = 120;
};