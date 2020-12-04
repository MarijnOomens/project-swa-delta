#include "NPC.h"

NPC::NPC(int x, int y, std::string& texture)
{
	this->textures.try_emplace("dialogue_box", "Assets/Dialogue/text_box.png");

	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });
	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = this->transform;
	gc->playAnimation(0, 3, animationSpeed, false);
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "npc";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void NPC::interact(std::shared_ptr<BehaviourObject> interactor)
{
	SceneLoader::getInstance().addOverlayScene("Dialogue");
}

void NPC::setParent() {
	cc->parent = shared_from_this();
}

void NPC::registerCollision(int x, int y, bool isDamaged, bool isTransitioned) {}