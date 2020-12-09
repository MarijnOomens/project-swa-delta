#include "Berry.h"

Berry::Berry(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc->transform = transform;
    gc->isScreen = false;

    stp = std::make_shared<StopStrategy>();
    cc = std::make_shared<CollidingComponent>(stp);
    cc->tag = "berry";
    cc->transform.position = this->transform.position;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

void Berry::interact(std::shared_ptr<BehaviourObject> interactor)
{
    auto col = dynamic_cast<Player*>(interactor.get());
    if(col != nullptr) { col->addBerry(); }
    

    if (gc != nullptr) {
        SceneModifier::getInstance().deleteObjectFromScene(gc);
        SceneModifier::getInstance().deleteColliderFromScene(cc);
        gc = nullptr;
    }
}

void Berry::use() {}

void Berry::setParent() {
    cc->parent = shared_from_this();
}

void Berry::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void Berry::update() {}

void Berry::start() {}