#pragma once
#include "InteractiveObject.h"
#include <string>
#include <map>
#include <GraphicsComponent.h>

class NPC : public InteractiveObject
{
public:
	NPC();
	~NPC();
	std::map<std::string, std::string> textures;
	void interact() override;
protected:
	std::string sfxPath;
private:
	std::string name;
	std::map<std::string, std::string> dialogue;
	std::shared_ptr<GraphicsComponent> gc;
};