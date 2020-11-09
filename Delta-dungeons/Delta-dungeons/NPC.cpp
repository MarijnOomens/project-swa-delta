#include "NPC.h"

const int animationSpeed = 120;

NPC::NPC(int x, int y, std::string texture) 
{
	this->transform.position = { x, y };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc.get()->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;
	this->components.emplace_back(gc);
}

NPC::~NPC() {}

void NPC::interact(){}