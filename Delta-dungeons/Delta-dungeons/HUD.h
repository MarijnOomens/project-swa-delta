#pragma once
#include "GameObject.h"
#include <memory>
#include "GraphicsComponent.h"
#include <map>
#include "SceneModifier.h"
#include "GameState.h"

class HUD : public GameObject
{
public:
	std::map<std::string, std::string> textures;
	std::map<std::string, std::string> fonts;
	std::vector<std::shared_ptr<GraphicsComponent>> hearts;
	std::vector<std::shared_ptr<GraphicsComponent>> items;
	HUD(int hM, int h, int b, int p);

	void updateCollectedCrystals(int param) {}
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override {}
	void update(int time) override;
	void setParent() override {}
	void start() override {}
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
	void interact(std::shared_ptr<BehaviourObject> interactor) override {}
	void addHealth();
	void deleteHealth();

private:
	int health = 0;
	int maxHealth = 0;
	int amountOfBerries = 0;
	bool hasRunningShoes = false;
	std::shared_ptr<TextComponent> berryCount;
	int amountOfPokeballs = 0;
	std::shared_ptr<TextComponent> ballsCount;
	int amountItems = 0;
	int collectedCrystals;
	std::shared_ptr<TextComponent> score;
};