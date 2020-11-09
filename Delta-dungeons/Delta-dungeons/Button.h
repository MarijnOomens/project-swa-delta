#pragma once

#include "GameObject.h"
#include "GraphicsComponent.h"
#include <string>
#include <memory>

typedef void(*buttonCb) (void*);

class Button : public GameObject
{
public:
	buttonCb onCLickFunc;
	void* pointer;
	Button();
	Button(int x, int y, std::vector<std::string> textureList, const buttonCb onClick, void* p);
	~Button();
	void update() override;
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) override;
private:
	std::string text;
	std::vector<std::string> possibleTextures;
	std::shared_ptr<GraphicsComponent> m_gc;
};