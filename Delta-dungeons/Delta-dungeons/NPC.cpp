#include "NPC.h"

NPC::NPC() 
{
	this->textures.try_emplace("npc", "Assets/npc_anims.png");
	this->transform.position = { 200, 200 };
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture("npc");
	gc.get()->transform = this->transform;
	gc->imageDimensions = { 32, 32 };
	gc->transform.scale.multiply({ 2, 2 });
	//gc->playAnimation(0, 3, animationSpeed, false);

	this->components.emplace_back(gc);
}

NPC::~NPC(){}

void NPC::interact(){}