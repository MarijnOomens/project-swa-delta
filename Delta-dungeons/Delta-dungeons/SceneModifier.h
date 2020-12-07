#pragma once
#include "EngineFacade.h"

class SceneModifier
{
public:
	static SceneModifier& getInstance();
	void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider);
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects);

private:
	static SceneModifier sceneModifier;
	std::shared_ptr<EngineFacade> engineFacade;
};