#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};

GraphicsComponent::~GraphicsComponent() {};

void GraphicsComponent::playAnimation(AnimTypes animationType, AnimFlip flipS) 
{
	animSpeed = 200;
	animated = true;
	flipped = false;

	if (flipS == FLIP)
	{
		flipped = true;
	}

	switch (animationType)
	{
	case IDLE_FRONT:
		animRow = 0;
		animFrames = 3;
		break;
	case IDLE_BACK:
		animRow = 4;
		animFrames = 3;
		break;
	case IDLE_SIDE:
		animRow = 5;
		animFrames = 3;
		break;
	case WALK_FRONT:
		animRow = 1;
		animFrames = 4;
		break;
	case WALK_BACK:
		animRow = 2;
		animFrames = 4;
		break;
	case WALK_SIDE:
		animRow = 3;
		animFrames = 4;
		break;
	case RUN_FRONT:
		animRow = 6;
		animFrames = 3;
		break;
	case RUN_BACK:
		animRow = 7;
		animFrames = 3;
		break;
	case RUN_SIDE:
		animRow = 8;
		animFrames = 3;
		break;
	}

	// Alleen geschikt voor een player. Wat als er andere objecten zijn met animations?
	// Mogelijk Animation klasse met properties animRow, animFrames, animSpeed etc.
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

std::shared_ptr<TextureManager> GraphicsComponent::getTextureManager() 
{
	return this->textureManager;
}
