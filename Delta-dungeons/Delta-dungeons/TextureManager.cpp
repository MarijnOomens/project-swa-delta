#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am) {
	assetManager = am;
	renderFacade = rf;
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name, Vector2D position) {
	std::string texturePath = assetManager->getTexture(name);
	renderFacade->drawTexture(texturePath.c_str(), position);
};
