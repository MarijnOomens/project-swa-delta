#pragma once
#include <map>
#include <string>
#include <vector>
#include "BehaviourObject.h"

class Scene
{
public:
	std::string name;

	std::vector<std::shared_ptr<BehaviourObject>> getBehaviourObjects();
	void setBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>>);

	std::map<std::string, std::string> getTextures();
	void setTextures(std::map<std::string, std::string>);

	std::map<std::string, std::string> getFonts();
	void setFonts(std::map<std::string, std::string>);

	std::map<std::string, std::string> getBeats();
	void setBeats(std::map<std::string, std::string>);
private:
	std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects;
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;
	std::map<std::string, std::string> beats;
};