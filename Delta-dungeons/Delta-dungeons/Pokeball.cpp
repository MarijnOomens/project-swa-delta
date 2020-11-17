#include "Pokeball.h"

Pokeball::Pokeball(int x, int y, std::string texture) {
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	cc = std::make_shared<ColliderComponent>();
	cc->tag = "pokeball";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

void Pokeball::interact()
{
	if (gc != nullptr) {
		std::cout << "Collected: " << gc->textureName << " x: " << gc->transform.position.x << " y: " << gc->transform.position.y << std::endl;
		SceneModifier::getInstance().deleteObjectFromScene(gc);
		SceneModifier::getInstance().deleteColliderFromScene(cc);
		gc = nullptr;
	}
}

void Pokeball::use() {}