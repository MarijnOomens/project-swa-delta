#include "HUD.h"

HUD::HUD(int health)
{
	this->textures.emplace("heart", "Assets/HUD/heart.png");
	transform.position = { 0 ,0 };
	for (int i = 0; i < health; i++)
	{
		addHealth(i);
	}
}

void HUD::updateHealth(int param) {}

void HUD::updateCollectedCrystals(int param) {}

void HUD::updateHighScore(int param) {}

void HUD::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) 
{
	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCode == KeyCodes::KEY_E) {
		addHealth(health);
	}

	if (keyboardEvent == KeyboardEvent::KEY_PRESSED && keyCode == KeyCodes::KEY_D) {
		deleteHealth();
	}
}

void HUD::update() {}

void HUD::interact() {}

void HUD::addHealth(int indexHeart)
{
	if (indexHeart < maxHealth) 
	{
		std::shared_ptr<GraphicsComponent> heartGc = std::make_shared<GraphicsComponent>();
		heartGc->setTexture("heart");
		heartGc->isScreen = true;
		heartGc->transform.position = { (indexHeart * 34) + 10, 20 };
		heartGc->imageDimensions = { 32, 32 };
		this->components.emplace_back(heartGc);
		this->hearts.emplace_back(heartGc);
		SceneModifier::getInstance().addObjectToScene(heartGc);
		health++;
		updateItems(health);
	}
}

void HUD::deleteHealth()
{
	if (health > 1)
	{
		std::shared_ptr<GraphicsComponent> heart = hearts.back();
		components.erase(std::find(components.begin(), components.end(), heart));
		hearts.erase(std::find(hearts.begin(), hearts.end(), heart));
		SceneModifier::getInstance().deleteObjectFromScene(heart);
		health--;
		updateItems(health);
	}
}

void HUD::addItem(const std::string& texturepath)
{
	std::shared_ptr<GraphicsComponent> itemGc = std::make_shared<GraphicsComponent>();
	itemGc->setTexture(texturepath);
	itemGc->isScreen = true;
	itemGc->transform.position = { (health * 34) + (amountItems * 34) + 10, 20 };
	itemGc->imageDimensions = { 32, 32 };
	this->components.emplace_back(itemGc);
	this->items.emplace_back(itemGc);
	SceneModifier::getInstance().addObjectToScene(itemGc);
	amountItems++;
}

void HUD::updateItems(int i)
{
	int itemIndex = 0;
	for (auto& item : items)
	{
		item->transform.position = { (i * 34) + (itemIndex * 34) + 10, 20 };
		//SceneModifier::getInstance().updateObjectToScene(item);
		itemIndex++;
	}
}