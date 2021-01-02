#include "RunningShoes.h"

RunningShoes::RunningShoes(const std::string& t)
{
	texture = t;
}

RunningShoes::RunningShoes(int x, int y, std::string texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	stp = std::make_shared<StopStrategy>();
	cc = std::make_shared<CollidingComponent>(stp);
	cc->tag = "runningshoes";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void RunningShoes::interact(std::shared_ptr<BehaviourObject> interactor)
{
	GameState::getInstance().setHasRunningShoes(true);

	if (gc != nullptr) {
		SceneModifier::getInstance().deleteObjectFromScene(gc);
		SceneModifier::getInstance().deleteColliderFromScene(cc);
		SceneModifier::getInstance().deleteObjectFromScene(shared_from_this());
		gc = nullptr;
	}
}

/// <summary>
/// This method gets called to change the isActivated boolean property. 
/// Afterwards it will pass the isActivated boolean to the Player.cpp class.
/// </summary>
void RunningShoes::use()
{
	isActivated = !isActivated;
}

void RunningShoes::setParent() {
	cc->parent = shared_from_this();
}