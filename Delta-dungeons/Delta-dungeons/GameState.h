#pragma once
#include <string>
#include "SaveSystem.h"

class GameState
{
public:
	static GameState& getInstance();

	void reset();
	void addCaughPokemon(int amount);
	int getCaughtPokemon();
	int getHighScore();
	void save();

private:
	static GameState gameState;
	GameState() {}

	SaveSystem saveSystem;

	std::string currentLevel = "Level1";
	int caughtPokemon = 0;
	int highScore = 0;
	int health = 5;
	int pokeBalls = 20;
	int berries = 0;
	bool hasBoomerang = false;
	bool hasRunningShoes = true;
	bool runningShoesActivated = false;
};
