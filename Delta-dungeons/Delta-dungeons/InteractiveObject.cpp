#include "InteractiveObject.h"

void InteractiveObject::update() {}
void InteractiveObject::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}
void InteractiveObject::interact(std::shared_ptr<BehaviourObject> player) {}

void InteractiveObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned) {}