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
    cc->tag = "boomerang";
    cc->transform.position = this->transform.position;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

void Boomerang::use() {}

void Boomerang::interact() 
{
    if (gc != nullptr) {
        std::cout << "found " << gc.get()->textureName << gc.get()->transform.position.x << " " << gc.get()->transform.position.y << std::endl;
        SceneModifier::getInstance().deleteObjectFromScene(gc);
        // delete collider component
        gc = nullptr;
    }
}
