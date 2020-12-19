#pragma once
#include <string>

class GameState
{
public:
	static GameState& getInstance();

	void reset();
	void addCaughPokemon(int amount);
	int getCaughtPokemon();
	int getHighScore();

private:
	static GameState gameState;
	GameState() {}

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
