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

	void updateHUD(int health, int berries, int pokeballs);
	void updateCollectedCrystals(int param);
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override;
	void update() override;
	void setParent() override;
	void start() override;

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void addHealth();
	void deleteHealth();
	void addItem(const std::string& texturepath);

private:
	int health = 0;
	int maxHealth = 0;
	int amountOfBerries = 0;
	std::shared_ptr<TextComponent> berryCount;
	int amountOfPokeballs = 0;
	std::shared_ptr<TextComponent> ballsCount;
	int amountItems = 0;
	int collectedCrystals;
	std::shared_ptr<TextComponent> score;
};