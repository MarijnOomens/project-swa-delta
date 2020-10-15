#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {
	textureManager = std::make_unique<TextureManager>();
};
GraphicsComponent::~GraphicsComponent() {};
void GraphicsComponent::PlayAnimation(std::string path) {};
//void GraphicsComponent::draw() { 
//	//grab the vector2D source and vector2D destination
//	GraphicsComponent::textureManager->DrawTexture();
//};
void GraphicsComponent::SetTexture(std::string name) {};
void GraphicsComponent::callbackFunction() {
};

void GraphicsComponent::Update() {
	textureManager->DrawTexture(textureName);
}

void GraphicsComponent::connectCallback() {

}