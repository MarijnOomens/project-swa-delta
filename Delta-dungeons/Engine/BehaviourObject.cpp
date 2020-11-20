#include "BehaviourObject.h"

/// <summary>
/// Behaviour objects are components like GrapicsComponent. This class 'manages' these components.
/// </summary>
BehaviourObject::BehaviourObject() {}
BehaviourObject::~BehaviourObject() {}

void BehaviourObject::update() {}

void BehaviourObject::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}

void BehaviourObject::interact() {}