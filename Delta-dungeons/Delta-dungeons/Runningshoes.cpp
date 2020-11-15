#include "RunningShoes.h"

RunningShoes::RunningShoes() {}

RunningShoes::RunningShoes(const cbEquipment f, void* p) : func(f), pointer(p) {}

RunningShoes::RunningShoes(int x, int y, std::string texture)
{
	this->transform.position = { x * 128, y * 128 };
	this->transform.scale.multiply({ 4, 4 });

	gc = std::make_shared<GraphicsComponent>();
	gc->setTexture(texture);
	gc->imageDimensions = { 32, 32 };
	gc.get()->transform = transform;
	gc->isScreen = false;

	cc = std::make_shared<ColliderComponent>();
	cc->tag = "runningshoes";
	cc->transform.position = this->transform.position;

	this->components.emplace_back(gc);
	this->components.emplace_back(cc);
}
RunningShoes::~RunningShoes() {}

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
	std::cout << "found " << gc.get()->textureName << gc.get()->transform.position.x << " " << gc.get()->transform.position.y << std::endl;
	SceneModifier::getInstance().deleteObjectFromScene(gc);
	SceneModifier::getInstance().deleteObjectFromScene(cc);
}