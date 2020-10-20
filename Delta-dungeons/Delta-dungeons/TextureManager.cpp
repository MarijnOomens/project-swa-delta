#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf, std::shared_ptr<AssetManager> am) {
	assetManager = am;
	renderFacade = rf;
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name) {
	std::string texturePath = assetManager->getTexture(name);
	Vector2D src(80, 50);
	Vector2D dest(160, 100);
	renderFacade->drawTexture(texturePath.c_str(), src, dest);
};
