#pragma once
#include "EngineFacade.h"

class SceneModifier
{
public:
	static SceneModifier& getInstance();
	void addObjectToScene(const std::shared_ptr<BehaviourObject>& addObject);
	void deleteObjectFromScene(const std::shared_ptr<BehaviourObject>& deletedObject);
	void deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider);
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);

private:
	static SceneModifier sceneModifier;
	std::shared_ptr<EngineFacade> engineFacade;
};