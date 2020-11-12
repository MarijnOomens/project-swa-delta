#include "RunningShoes.h"

RunningShoes::RunningShoes() {}

RunningShoes::RunningShoes(cbEquipment f, void* p) : func(f), pointer(p) {}


RunningShoes::RunningShoes(int x, int y, std::string texture)
{
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc.get()->transform = transform;
    gc->isScreen = false;
    this->components.emplace_back(gc);
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