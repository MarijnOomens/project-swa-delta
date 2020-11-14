#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

typedef void(*buttonCb) (const void*);

class Advertisement : public GameObject
{
public:
	Advertisement(int x, int y, const std::vector<std::string>& textureList);
	~Advertisement() {}
	void update() override;
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;

private:
	buttonCb onCLickFunc;
	const void* pointer;
	std::string text;
	std::vector<std::string> possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
}; 
