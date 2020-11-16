#pragma once
#include "GameObject.h"
#include <memory>
#include "GraphicsComponent.h"
#include <map>
#include "SceneModifier.h"

class HUD: public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::vector<std::shared_ptr<GraphicsComponent>> hearts;
	std::vector<std::shared_ptr<GraphicsComponent>> items;
	HUD(int health);
	~HUD() {}

	void updateHealth(int param);
	void updateCollectedCrystals(int param);
	void updateHighScore(int param);
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void addHealth(int indexHeart);
	void deleteHealth();
	void addItem(const std::string& texturepath);
	void updateItems(int i);

private:
	int health = 0;
	int maxHealth = 5;
	int amountItems = 0;
	int collectedCrystals;
	int highScore;
};