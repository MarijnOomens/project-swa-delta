#include "Pokeball.h"

Pokeball::Pokeball() {}

Pokeball::Pokeball(int x, int y, std::string texture) {
    this->transform.position = { x * 128, y * 128 };
    this->transform.scale.multiply({ 4, 4 });

    gc = std::make_shared<GraphicsComponent>();
    gc->setTexture(texture);
    gc->imageDimensions = { 32, 32 };
    gc.get()->transform = transform;
    gc->isScreen = false;
    this->components.emplace_back(gc);
}

Pokeball::~Pokeball() {}

void Pokeball::use() {}