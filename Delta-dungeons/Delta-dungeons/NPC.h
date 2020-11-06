#pragma once
#include "InteractiveObject.h"
#include <string>
#include <map>
#include <GraphicsComponent.h>

class NPC : public InteractiveObject
{
public:
	NPC(int x, int y, std::string texture);
	~NPC();
	void interact() override;
	void updatePositions(int x, int y) override;
protected:
	std::string sfxPath;
private:
	std::shared_ptr<GraphicsComponent> gc;
};