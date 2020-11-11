#include "GameObject.h"

/// <summary>
/// A gameObject is an object within the game.
/// </summary>
GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}


void GameObject::update() {}

/// <summary>
/// This method returns a list of all gameObjects within a gameObject. The method is recursive to get all underlying objects.
/// </summary>
/// <returns>Returns a vector of all objects under this gameObject.</returns>
std::vector<std::shared_ptr<BehaviourObject>> GameObject::getComponentsRecursive() {
	std::vector<std::shared_ptr<BehaviourObject>> tempObjs;
	for (auto& o : components) {
		if (dynamic_cast<GameObject*>(o.get()) != nullptr)
		{
			if (dynamic_cast<GameObject*>(o.get())->components.size() > 0) {
				auto result = dynamic_cast<GameObject*>(o.get())->getComponentsRecursive();
				for (auto& go : result) {
					tempObjs.emplace_back(go);
				}
			}
		}
		tempObjs.emplace_back(o);
	}
	return tempObjs;
}