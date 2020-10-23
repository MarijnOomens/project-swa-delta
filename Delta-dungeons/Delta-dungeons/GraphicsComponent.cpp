#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};
GraphicsComponent::GraphicsComponent(int spriteW, int spriteH) {
	transform.spriteLocationInPNG.spriteLocationInPNGWidth = spriteW;
	transform.spriteLocationInPNG.spriteLocationInPNGHeight = spriteH;
};

GraphicsComponent::~GraphicsComponent() {};

void GraphicsComponent::PlayAnimation(std::string path) {};

void GraphicsComponent::SetTexture(std::string name)
{
	textureName = name;
}

void GraphicsComponent::callbackFunction() {}


void GraphicsComponent::Update()
{
	textureManager->DrawTexture(textureName, this->transform.position, this->transform.spriteLocationInPNG);
}

void GraphicsComponent::connectCallback() {}

void GraphicsComponent::addTextureManager(std::shared_ptr<TextureManager> tm)
{
	textureManager = tm;
}

void GraphicsComponent::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {}