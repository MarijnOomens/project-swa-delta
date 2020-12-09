#include "Scene.h"

std::vector<std::shared_ptr<BehaviourObject>> Scene::getBehaviourObjects() const
{
	return behaviourObjects;
}

void Scene::setBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> bo)
{
	behaviourObjects = bo;
}

std::map<std::string, std::string> Scene::getTextures() const
{
	return textures;
}

void Scene::setTexture(const std::string& name, const std::string& t)
{
	textures.try_emplace(name, t);
}

std::map<std::string, std::string> Scene::getFonts() const
{
	return fonts;
}

void Scene::setFont(const std::string& name, const std::string& f)
{
	fonts.try_emplace(name, f);
}

std::map<std::string, std::string> Scene::getBeats() const
{
	return beats;
}

void Scene::setBeat(const std::string& name, const std::string& b)
{
	beats.try_emplace(name, b);
}
