#include "TextureManager.h"

TextureManager::TextureManager() {
	assetManager = std::make_unique<AssetManager>();
	renderFacade = std::make_unique<RenderFacade>();
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name) {

	assetManager->addTexture("button_play", "Assets/button_play.png");
	std::string path = assetManager->getTexture(name);
	Vector2D rect(32, 64);
	Vector2D dest(100, 100);
	renderFacade->drawTexture("assets/button_play.png", rect, dest);
	
};
