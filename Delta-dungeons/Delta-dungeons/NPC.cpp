#include "NPC.h"

NPC::NPC() 
{
	this->textures.try_emplace("npc", "Assets/npc_anims.png");
	this->transform.position = { 200, 200 };
	this->transform.scale.multiply({ 2, 2 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("npc");
	gc->imageDimensions = { 32, 32 };
	gc.get()->transform = this->transform;
	//gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(gc);
}

NPC::~NPC(){}

void NPC::interact(){}

void NPC::updatePositions(int x, int y) 
{
	this->transform.position.x = this->transform.position.x - x;
	this->transform.position.y = this->transform.position.y - y;
	gc.get()->transform = transform;
}