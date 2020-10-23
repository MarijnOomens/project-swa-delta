#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am) {
	assetManager = am;
	renderFacade = rf;
};

TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {}

void TextureManager::DrawTexture(std::string name, Vector2D position, Vector2D sprite) 
{
	std::string path = assetManager->getTexture(name);
	renderFacade->drawTexture(path.c_str(), position, sprite);
	
}