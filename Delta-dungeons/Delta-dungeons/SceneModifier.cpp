#include "SceneModifier.h"

SceneModifier SceneModifier::sceneModifier;

SceneModifier& SceneModifier::getInstance()
{
	return sceneModifier;
}

void SceneModifier::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	engineFacade->deleteObjectFromScene(deletedObject);
}

void SceneModifier::deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider)
{
	engineFacade->deleteColliderFromScene(deletedCollider);
}

void SceneModifier::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}