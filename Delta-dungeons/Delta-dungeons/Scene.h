#pragma once
#include <map>
#include <string>
#include <vector>
#include "BehaviourObject.h"
#include "GameObject.h"

class Scene
{
public:
	std::string name;

	std::vector<std::shared_ptr<BehaviourObject>> getBehaviourObjects();
	void setBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>>);

	std::map<std::string, std::string> getTextures();
	void setTexture(const std::string& name, const std::string& t);

	std::map<std::string, std::string> getFonts();
	void setFont(const std::string& name, const std::string& t);

	std::map<std::string, std::string> getBeats();
	void setBeat(const std::string& name, const std::string& t);
private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;
	std::map<std::string, std::string> beats;
};