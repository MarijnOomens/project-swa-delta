#include "Berry.h"

Berry::Berry(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc->transform = transform;
    gc->isScreen = false;
    
    cc = std::make_shared<CollidingComponent>();
    cc->tag = "berry";
    cc->transform.position = this->transform.position;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

void Berry::interact() 
{
    if (gc != nullptr) {
        SceneModifier::getInstance().deleteObjectFromScene(gc);
        SceneModifier::getInstance().deleteColliderFromScene(cc);
        gc = nullptr;
    }
}

void Berry::use() {}