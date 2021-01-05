#include "GraphicsComponent.h"

void GraphicsComponent::playAnimation(int row, int frames, int speed, bool flip) 
{
	animated = true;
	animRow = row;
	animFrames = frames;
	animSpeed = speed;
	flipped = flip;
}

/// <summary>
/// Sets the texture of the graphicsComponent.
/// </summary>
/// <param name="name">Texture name.</param>
void GraphicsComponent::setTexture(const std::string& name)
{
	this->textureName = name;
}

/// <summary>
/// Calls the textureManager to draw the texture to the screen.
/// </summary>
void GraphicsComponent::update(int time)
{
	textureManager->drawTexture(textureName, this->transform, this->imageCoordinates, this->imageDimensions, animRow, animFrames, animSpeed, animated, flipped, isScreen);
}

/// <summary>
/// Adds a reference to the global textureManager.
/// </summary>
/// <param name="tm">The textureManager</param>
void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos) {}

void GraphicsComponent::interact(std::shared_ptr<BehaviourObject> interactor) {}

void GraphicsComponent::start() {}

void GraphicsComponent::setParent() {}
/// <summary>
/// Gets the textureManager pointer.
/// </summary>
/// <returns>Returns the textureManager pointer.</returns>
std::shared_ptr<TextureManager> GraphicsComponent::getTextureManager() const
{
	return this->textureManager;
}