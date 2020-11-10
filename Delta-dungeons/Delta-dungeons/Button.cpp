#include "Button.h"
/// <summary>
/// This class creates the button which will be used within, credit- and mainmenu screen
/// </summary>
Button::Button() {};

/// <summary>
/// The constructor intialises the graphicscomponent and defines the size, scale and textures.
/// </summary>
/// <param name="x">The horizontal position</param>
/// <param name="y">The vertical position</param>
/// <param name="textureList">Information of texture names.</param>
Button::Button(int x, int y, std::vector<std::string> textureList, buttonCb onClick, void* p) : onCLickFunc(onClick), pointer(p) {
	m_gc = std::make_shared<GraphicsComponent>();
	transform.position = { x, y };

	m_gc->transform = this->transform;
	m_gc->imageDimensions = { 140, 50 };
	m_gc->transform.scale.multiply({ 2, 2 });

	possibleTextures = textureList;
	m_gc->setTexture(possibleTextures[0]);
	this->components.emplace_back(m_gc);
};

Button::~Button() {}

void Button::update() {}

void Button::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos) {
	if (keyboardEvent == KeyboardEvent::MOUSE_CLICKED)
	{
		// Checks if the mouse is clicked while mouse pointer is positioned inside the texture bounds
		if (mousePos.x > m_gc.get()->transform.position.x && mousePos.x < m_gc.get()->transform.position.x + m_gc.get()->imageDimensions.x * m_gc.get()->transform.scale.x
			&& mousePos.y > m_gc.get()->transform.position.y && mousePos.y < m_gc.get()->transform.position.y + m_gc.get()->imageDimensions.y * m_gc.get()->transform.scale.y)
		{
			onCLickFunc(pointer);
		}
	}
}

void Button::connectCallback() {}

void Button::callbackFunction() {}
