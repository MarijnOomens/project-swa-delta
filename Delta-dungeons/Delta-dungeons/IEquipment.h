#pragma once
#include <string>
#include "GameObject.h"
#include <map>
#include "SceneModifier.h"

class IEquipment : public GameObject
{
public:
	std::string texture;
	std::string name;
	std::string collectMessage;
	std::map<std::string, std::string> textures;

	virtual void use() = 0;
};