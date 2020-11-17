#include "RunningShoes.h"

RunningShoes::RunningShoes(const cbEquipment f, void* p) : func(f), pointer(p) {}

RunningShoes::RunningShoes(int x, int y, std::string texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc->transform = transform;
	gc->isScreen = false;

	cc = std::make_shared<ColliderComponent>();
	cc->tag = "runningshoes";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}

/// <summary>
/// This method gets called to change the isActivated boolean property. 
/// Afterwards it will pass the isActivated boolean to the Player.cpp class.
/// </summary>
void RunningShoes::use()
{
	isActivated = !isActivated;
	std::cout << isActivated << std::endl;
	func(pointer, isActivated);
}

void RunningShoes::interact()
{
	if (gc != nullptr) {
		std::cout << "found " << gc->textureName << gc->transform.position.x << " " << gc->transform.position.y << std::endl;
		SceneModifier::getInstance().deleteObjectFromScene(gc);
		SceneModifier::getInstance().deleteColliderFromScene(cc);
		gc = nullptr;
	}
}