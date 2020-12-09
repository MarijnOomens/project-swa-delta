#include "Advertisement.h"

/// <summary>
/// The constructor intialises the graphicscomponent and defines the size, scale and textures.
/// </summary>
/// <param name="x">The horizontal position</param>
/// <param name="y">The vertical position</param>
/// <param name="textureList">Information of texture names.</param>
Advertisement::Advertisement(int x, int y, const std::vector<std::string>& textureList)
{
	m_gc = std::make_shared<GraphicsComponent>();
	transform.position = { x, y };

	m_gc->transform = this->transform;
	m_gc->imageDimensions = { 410, 70 };
	m_gc->transform.scale.multiply({ 1, 1 });
	m_gc->isScreen = true;

	possibleTextures = textureList;
	m_gc->setTexture(possibleTextures[0]);
	this->components.emplace_back(m_gc);
}

void Advertisement::update() {}

void Advertisement::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) {}

void Advertisement::interact(std::shared_ptr<BehaviourObject> interactor) {}

void Advertisement::setParent() {}

void Advertisement::start() {}