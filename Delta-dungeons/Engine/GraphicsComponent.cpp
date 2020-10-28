#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};

GraphicsComponent::~GraphicsComponent() {};

void GraphicsComponent::playAnimation(std::string animationType, AnimFlip flipS) 
{
	// IMPLEMENTEER SWITCH HIER OOIT
	animSpeed = 500;
	animated = true;
	
	if (flipS == FLIP)
	{
		flipped = true;
	}
	else
	{
		flipped = false;
	}


	if (animationType == "idle_front")
	{
		animRow = 0;
		animFrames = 3;
	}
	else if (animationType == "idle_back")
	{
		animRow = 4;
		animFrames = 3;
	}
	else if (animationType == "idle_side")
	{
		animRow = 5;
		animFrames = 3;
	}
	else if (animationType == "walk_front")
	{
		animRow = 1;
		animFrames = 4;
	}
	else if (animationType == "walk_back")
	{
		animRow = 2;
		animFrames = 4;
	}
	else if (animationType == "walk_side")
	{
		animRow = 3;
		animFrames = 4;
	}
	else if (animationType == "run_front")
	{
		animRow = 6;
		animFrames = 3;
	}
	else if (animationType == "run_back")
	{
		animRow = 7;
		animFrames = 3;
	}
	else if (animationType == "run_side")
	{
		animRow = 8;
		animFrames = 4;
	}

	
	// We kunnen mogelijk de waarden in RenderFacade.cpp aanpassen, zodat we dan niet animRow mee hoeven te geven...
	// Fix enum switch statement
	// Alleen geschikt voor een player. Wat als er andere objecten zijn met animations?

}

void GraphicsComponent::setTexture(std::string name)
{
	this->textureName = name;
}

void GraphicsComponent::update()
{
	textureManager->drawTexture(textureName, this->transform, this->imageCoordinates, this->imageDimensions, animRow, animFrames, animSpeed, animated, flipped);


}

void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::callbackFunction() {}

void GraphicsComponent::connectCallback() {}

void GraphicsComponent::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}

std::shared_ptr<TextureManager> GraphicsComponent::getTextureManager() {
	return this->textureManager;
}
