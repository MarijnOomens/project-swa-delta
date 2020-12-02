#include "Scene.h"

std::vector<std::shared_ptr<BehaviourObject>> Scene::getBehaviourObjects()
{
	return behaviourObjects;
}

void Scene::setBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> bo)
{
	behaviourObjects = bo;
}

std::map<std::string, std::string> Scene::getTextures()
{
	return textures;
}

void Scene::setTextures(std::map<std::string, std::string> t)
{
	textures = t;
}

std::map<std::string, std::string> Scene::getFonts()
{
	return fonts;
}

void Scene::setFonts(std::map<std::string, std::string> f)
{
	fonts = f;
}

std::map<std::string, std::string> Scene::getBeats()
{
	return beats;
}

void Scene::setBeats(std::map<std::string, std::string> b)
{
	beats = b;
}