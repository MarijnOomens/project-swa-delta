#include "SceneModifier.h"

SceneModifier SceneModifier::sceneModifier;

SceneModifier& SceneModifier::getInstance()
{
	return sceneModifier;
}

void SceneModifier::addObjectToScene(std::shared_ptr<BehaviourObject> addObject)
{
	engineFacade->addObjectToScene(addObject);
}

void SceneModifier::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	engineFacade->deleteObjectFromScene(deletedObject);
}

void SceneModifier::deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider)
{
	engineFacade->deleteColliderFromScene(deletedCollider);
}

void SceneModifier::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}

void SceneModifier::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects)
{
	engineFacade->replaceScene(sceneName, objects);
}