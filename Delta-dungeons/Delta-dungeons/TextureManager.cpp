#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<RenderFacade> rf) {
	assetManager = std::make_unique<AssetManager>();
	renderFacade = rf;
};
TextureManager::~TextureManager() {};

void TextureManager::LoadTexture() {};
void TextureManager::DrawTexture(std::string name) {

	//assetManager->addTexture("button_play", "assets/button_play.png");
	//std::string path = assetManager->getTexture(name);
	Vector2D src(32, 32);
	Vector2D dest(96, 96);
	renderFacade->drawTexture("Assets/button_play.png", src, dest);
	
};
