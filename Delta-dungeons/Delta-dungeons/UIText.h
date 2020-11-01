#pragma once
#include "GameObject.h"
#include "Colour.h"
#include "TextureManager.h"
#include <GraphicsComponent.h>

class UIText : public GameObject
{
public:
	UIText();
	UIText(int x, int y, std::string text, Colour colour);
	~UIText();
	void update() override;
	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;
private:
	std::string text;
	std::string font;
	Colour color;
	std::shared_ptr<GraphicsComponent> m_gc;
};