#include "Berry.h"

Berry::Berry() {}

Berry::Berry(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc.get()->transform = transform;
    gc->isScreen = false;
    
    cc = std::make_shared<ColliderComponent>();
    cc->tag = "berry";
    cc->transform.position = this->transform.position;
    cc->isTrigger = true;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

Berry::~Berry() {}

void Berry::use() {}

void Berry::interact() 
{
    if (gc != nullptr) {
        std::cout << "found " << gc.get()->textureName << gc.get()->transform.position.x << " " << gc.get()->transform.position.y << std::endl;
        SceneModifier::getInstance().deleteObjectFromScene(gc);
        SceneModifier::getInstance().deleteObjectFromScene(cc);
        gc = nullptr;
    }

}
