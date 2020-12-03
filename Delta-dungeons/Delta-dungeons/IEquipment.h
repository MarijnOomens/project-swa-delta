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
	void setParent() override;

	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
};