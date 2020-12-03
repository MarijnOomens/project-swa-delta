#include "IInteractiveObject.h"

void IInteractiveObject::update() {}
void IInteractiveObject::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}
void IInteractiveObject::interact(std::shared_ptr<BehaviourObject> player) {}

void IInteractiveObject::registerCollision(int x, int y, bool isDamaged, bool isTransitioned) {}