#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

typedef void(*buttonCb) (const void*);

class Button : public GameObject
{
public:
	Button(int x, int y, const std::vector<std::string>& textureList, const buttonCb onClick, const void* p);
	void update() override;
	void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) override;
	void interact(std::shared_ptr<BehaviourObject> interactor) override;

private:
	buttonCb onCLickFunc;
	const void* pointer;
	std::string text;
	std::vector<std::string> possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
};