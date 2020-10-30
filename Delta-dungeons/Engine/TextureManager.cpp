#include "TextureManager.h"

TextureManager::TextureManager() {}

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am)
{
	assetManager = am;
	renderFacade = rf;
}

TextureManager::~TextureManager() {}

void TextureManager::loadTexture() {}

void TextureManager::drawTexture(const std::string name, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions)
{
	std::string texturePath = assetManager->getTexture(name);
	renderFacade->drawTexture(texturePath, transform, coordinates, sourceDimensions);
}

void TextureManager::drawText(std::string text, std::string fontName, Colour colour, const Transform& transform) 
{
	std::string fontPath = assetManager->getFont(fontName);
}
