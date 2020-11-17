#pragma once
#include "EngineFacade.h"

class SceneModifier
{
public:
	static SceneModifier& getInstance();
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider);
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);

private:
	static SceneModifier sceneModifier;
	std::shared_ptr<EngineFacade> engineFacade;
};