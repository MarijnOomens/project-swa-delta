#include "NPC.h"

NPC::NPC(int x, int y, std::string &texture) 
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;
	this->components.emplace_back(gc);
}

void NPC::interact()
{
	std::cout << "found " << gc.get()->textureName << gc.get()->transform.position.x << " " << gc.get()->transform.position.y << std::endl;
}