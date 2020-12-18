#include "Pokeball.h"

Pokeball::Pokeball(int x, int y, std::string texture) 
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
	cc->tag = "pokeball";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void Pokeball::interact(std::shared_ptr<BehaviourObject> interactor)
{
	AudioUtilities::getInstance().playEffect("pickup");
	auto col = dynamic_cast<Player*>(interactor.get());
	col->addPokeball();

	if (gc != nullptr) {
		SceneModifier::getInstance().deleteObjectFromScene(gc);
		SceneModifier::getInstance().deleteColliderFromScene(cc);
		SceneModifier::getInstance().deleteObjectFromScene(shared_from_this());
		gc = nullptr;
	}
}

void Pokeball::setParent() 
{
	cc->parent = shared_from_this();
}