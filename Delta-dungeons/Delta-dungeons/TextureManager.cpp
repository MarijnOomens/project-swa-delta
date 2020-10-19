#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf) {
	assetManager = std::make_unique<AssetManager>();
	renderFacade = rf;
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name) {
	
};
