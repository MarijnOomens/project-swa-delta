#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};

GraphicsComponent::~GraphicsComponent() {};

void GraphicsComponent::playAnimation(std::string path) {};

void GraphicsComponent::setTexture(std::string name)
{
	this->textureName = name;
}

void GraphicsComponent::callbackFunction() {}


void GraphicsComponent::update()
{
	textureManager->DrawTexture(textureName, this->transform.position, this->imageCoordinates);
}

void GraphicsComponent::connectCallback() {}

void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}