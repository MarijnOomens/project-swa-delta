#include "GraphicsComponent.h"

/// <summary>
/// A GraphicsComponent holds the graphical details of a gameObject, like animation and textures.
/// </summary>

/// <summary>
/// If the graphicsComponent is animated, this method will start to play the animation.
/// </summary>
/// <param name="row">The row of which animation frame to take.</param>
/// <param name="frames">The amount of frames in an animation.</param>
/// <param name="speed">The speed of the animation.</param>
/// <param name="flip">If the animation is flipped or not.</param>
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
void GraphicsComponent::update()
{
	textureManager->drawTexture(textureName, this->transform, this->imageCoordinates, this->imageDimensions, animRow, animFrames, animSpeed, animated, flipped,isScreen);
}

/// <summary>
/// Adds a reference to the global textureManager.
/// </summary>
/// <param name="tm">The textureManager</param>
void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::callbackFunction() {}

void GraphicsComponent::connectCallback() {}

/// <summary>
/// Gets the textureManager pointer.
/// </summary>
/// <returns>Returns the textureManager pointer.</returns>
std::shared_ptr<TextureManager> GraphicsComponent::getTextureManager() 
{
	return this->textureManager;
}