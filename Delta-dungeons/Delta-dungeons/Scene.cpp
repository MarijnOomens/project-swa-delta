#include "Scene.h"

void Scene::registerBehaviourObjects()
{
	for (auto& o : behaviourObjects)
	{
		if (dynamic_cast<GameObject*>(o.get()) != nullptr)
		{
			auto go = dynamic_cast<GameObject*>(o.get());
			auto gor = go->getComponentsRecursive();
			behaviourObjects.insert(behaviourObjects.end(), gor.begin(), behaviourObjects.end());
		}
	}
}

std::vector<std::shared_ptr<BehaviourObject>> Scene::getBehaviourObjects()
{
	return behaviourObjects;
}

void Scene::setBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> bo)
{
	behaviourObjects = bo;
	registerBehaviourObjects();
}

std::map<std::string, std::string> Scene::getTextures()
{
	return textures;
}

void Scene::setTexture(const std::string& name, const std::string& t)
{
	textures.try_emplace(name, t);
}

std::map<std::string, std::string> Scene::getFonts()
{
	return fonts;
}

void Scene::setFont(const std::string& name, const std::string& f)
{
	textures.try_emplace(name, f);
}

std::map<std::string, std::string> Scene::getBeats()
{
	return beats;
}

void Scene::setBeat(const std::string& name, const std::string& b)
{
	textures.try_emplace(name, b);
}