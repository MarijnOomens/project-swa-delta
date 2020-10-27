#include "TextureManager.h"

TextureManager::TextureManager() {}

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am)
{
	assetManager = am;
	renderFacade = rf;
};

TextureManager::~TextureManager() {}

void TextureManager::loadTexture() {}

void TextureManager::drawTexture(std::string name, Vector2D position, Vector2D coordinates)
{
	std::string texturePath = assetManager->getTexture(name);
	renderFacade->drawTexture(texturePath, position, coordinates);
}