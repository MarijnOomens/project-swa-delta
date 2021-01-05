#include "GameObject.h"

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