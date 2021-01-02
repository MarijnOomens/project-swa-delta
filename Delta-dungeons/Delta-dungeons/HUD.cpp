#include "HUD.h"

HUD::HUD(int hM, int h, int b, int p)
{
	this->textures.emplace("heart", "Assets/HUD/heart.png");
	this->textures.emplace("deadheart", "Assets/HUD/deadheart.png");
	this->textures.emplace("runningshoesHUD", "Assets/HUD/Runningshoes.png");
	this->textures.emplace("empty", "Assets/HUD/empty.png");
	this->fonts.try_emplace("joystix", "Assets/joystix.ttf");

	maxHealth = hM;
	health = h;

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

	std::shared_ptr<GraphicsComponent> itemGc = std::make_shared<GraphicsComponent>();
	itemGc->setTexture("empty");
	itemGc->isScreen = true;
	itemGc->transform.position = { (maxHealth * 34) + 10, 20 };
	itemGc->imageDimensions = { 32, 32 };
	this->components.emplace_back(itemGc);
	this->items.emplace_back(itemGc);

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

void HUD::update(int time)
{
	int scoreInt = GameState::getInstance().getCaughtPokemon();
	score->changeText("Score " + std::to_string(scoreInt));
	int berryInt = GameState::getInstance().getBerries();
	berryCount->changeText(std::to_string(berryInt));
	int pokeballInt = GameState::getInstance().getPokeballs();
	ballsCount->changeText(std::to_string(pokeballInt));
	
	if (GameState::getInstance().getHasRunningShoes() != hasRunningShoes)
	{
		items[0]->setTexture("runningshoesHUD");
	}

	if (GameState::getInstance().getHealth() < health) {
		deleteHealth();
	}
	else if (GameState::getInstance().getHealth() > health) {
		addHealth();
	}
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