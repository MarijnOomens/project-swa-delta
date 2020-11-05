#pragma once

#include "InteractiveObject.h"
#include <string>
#include <map>
#include "GraphicsComponent.h"

class Pokemon : public InteractiveObject
{
public:
	Pokemon(int x, int y, std::string texture);
	~Pokemon();
	void interact() override;
	void updatePositions(int x, int y) override;
protected:
	std::string sfxPath;
private:
	std::shared_ptr<GraphicsComponent> gc;
	std::string type;
	int id;
	int catchRate;
};