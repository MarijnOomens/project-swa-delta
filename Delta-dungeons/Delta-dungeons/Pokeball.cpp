#include "Pokeball.h"

Pokeball::Pokeball(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc.get()->transform = transform;
    gc->isScreen = false;

    cc = std::make_shared<ColliderComponent>();
    cc.get()->x = x * 128;
    cc.get()->y = y * 128;

    this->components.emplace_back(gc);
    this->components.emplace_back(cc);
}

Pokeball::~Pokeball() {}

void Pokeball::interact() {}

void Pokeball::use() {}