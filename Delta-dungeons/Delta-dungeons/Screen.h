#pragma once

#include <string>
#include <vector>
#include "GraphicsComponent.h"

class Screen : public GameObject
{
public:
	std::unique_ptr<GraphicsComponent> gc;
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;

	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void update() override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void start() override;
};