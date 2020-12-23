#include "HUD.h"

HUD::HUD(int hM, int h, int b, int p)
{
	this->textures.emplace("heart", "Assets/HUD/heart.png");
	this->textures.emplace("deadheart", "Assets/HUD/deadheart.png");
	this->fonts.try_emplace("joystix", "Assets/joystix.ttf");

	maxHealth = hM;
	health = h;
	amountOfBerries = b;
	amountOfPokeballs = p;

	transform.position = { 0 ,0 };

	Colour color = { 0, 0, 0, 255 };
	std::unique_ptr<TextComponent> healthText = std::make_unique<TextComponent>("Health", "joystix", color, 32);
	healthText->transform.position = { 10, 10 };
	this->components.emplace_back(std::move(healthText));

	for (int i = 0; i < maxHealth; i++)
	{
		std::shared_ptr<GraphicsComponent> heartGc = std::make_shared<GraphicsComponent>();
		if (i <= h) 
		{
			heartGc->setTexture("heart");
		}
		else 
		{
			heartGc->setTexture("deadheart");
		}
		heartGc->isScreen = true;
		heartGc->transform.position = { 210 + (i * 34) + 10, 15 };
		heartGc->imageDimensions = { 32, 32 };
		this->components.emplace_back(heartGc);
		this->hearts.emplace_back(heartGc);
	}

	std::unique_ptr<TextComponent> berryLabel = std::make_unique<TextComponent>("Berries", "joystix", color, 32);
	berryLabel->transform.position = { 10, 40 };
	this->components.emplace_back(std::move(berryLabel));

	berryCount = std::make_shared<TextComponent>(std::to_string(amountOfBerries), "joystix", color, 32);
	berryCount->transform.position = { 220, 40 };
	this->components.emplace_back(berryCount);

	std::unique_ptr<TextComponent> ballsLabel = std::make_unique<TextComponent>("PkBalls", "joystix", color, 32);
	ballsLabel->transform.position = { 10, 70 };
	this->components.emplace_back(std::move(ballsLabel));

	ballsCount = std::make_shared<TextComponent>(std::to_string(amountOfPokeballs), "joystix", color, 32);
	ballsCount->transform.position = { 220, 70 };
	this->components.emplace_back(ballsCount);

	score = std::make_shared<TextComponent>("", "joystix", color, 32);
	score->transform.position = { 10, 100 };
	this->components.emplace_back(score);
}

void HUD::updateHUD(int h, int b, int p)
{
	GameState::getInstance().setHealth(h);
	if (h < health) {
		deleteHealth();
	}
	else if(h > health){
		addHealth();
	}
	amountOfBerries = b;
	berryCount->changeText(std::to_string(amountOfBerries));
	amountOfPokeballs = p;
	GameState::getInstance().setPokeballs(p);
	ballsCount->changeText(std::to_string(amountOfPokeballs));
}

void HUD::update() 
{
	int scoreInt = GameState::getInstance().getCaughtPokemon();
	score->changeText("Score " + std::to_string(scoreInt));
}

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