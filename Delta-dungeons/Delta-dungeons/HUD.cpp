#include "HUD.h"

HUD::HUD(int h)
{
	this->textures.emplace("heart", "Assets/HUD/heart.png");
	this->textures.emplace("deadheart", "Assets/HUD/deadheart.png");
	transform.position = { 0 ,0 };
	for (int i = 0; i < maxHealth; i++)
	{
		std::shared_ptr<GraphicsComponent> heartGc = std::make_shared<GraphicsComponent>();
		if (i <= h) 
		{
			heartGc->setTexture("heart");
			health++;
		}
		else 
		{
			heartGc->setTexture("deadheart");
		}
		heartGc->isScreen = true;
		heartGc->transform.position = { (i * 34) + 10, 20 };
		heartGc->imageDimensions = { 32, 32 };
		this->components.emplace_back(heartGc);
		this->hearts.emplace_back(heartGc);
	}
}

void HUD::updateHealth(bool hit) 
{
	if (hit)
	{
		deleteHealth();
	}
	else
	{
		addHealth();
	}
}

void HUD::updateCollectedCrystals(int param) {}

void HUD::updateHighScore(int param) {}

void HUD::handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos){}

void HUD::update() {}

void HUD::interact(std::shared_ptr<BehaviourObject> interactor) {}

void HUD::addHealth()
{
	if (health < maxHealth) 
	{
		hearts[health]->setTexture("heart");
		health++;
	}
}

void HUD::deleteHealth()
{
	if (health > 0)
	{
		health--;
		hearts[health]->setTexture("deadheart");
	}
}

void HUD::addItem(const std::string& texturepath)
{
	std::shared_ptr<GraphicsComponent> itemGc = std::make_shared<GraphicsComponent>();
	itemGc->setTexture(texturepath);
	itemGc->isScreen = true;
	itemGc->transform.position = { (maxHealth * 34) + (amountItems * 34) + 10, 20 };
	itemGc->imageDimensions = { 32, 32 };
	this->components.emplace_back(itemGc);
	this->items.emplace_back(itemGc);
	SceneModifier::getInstance().addObjectToScene(itemGc);
	amountItems++;
}