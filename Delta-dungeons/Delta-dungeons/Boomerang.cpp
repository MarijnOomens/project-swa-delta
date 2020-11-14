#include "Boomerang.h"

Boomerang::Boomerang(int x, int y, std::string texture)
{
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc.get()->transform = transform;
    gc->isScreen = false;

    cc = std::make_shared<ColliderComponent>();
    cc->x = x * 128;
    cc->y = y * 128;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

void Boomerang::use() {}

void Boomerang::interact() {}
