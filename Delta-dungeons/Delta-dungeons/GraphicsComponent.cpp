#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {};
GraphicsComponent::~GraphicsComponent() {
	GraphicsComponent::textureManager = new TextureManager();
};
void GraphicsComponent::PlayAnimation(std::string path) {};
void GraphicsComponent::SetTexture(std::string tex) {};
void GraphicsComponent::CallBackFunction() {};
void GraphicsComponent::draw() { 
	//grab the vector2D source and vector2D destination
	GraphicsComponent::textureManager->DrawTexture();
};