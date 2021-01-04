#pragma once
#include <string>

class GameStateObject {
public:
	GameStateObject() {}
	GameStateObject(const std::string& lvl, int caughtPokemon, int highScore, int health, int pokeBalls, int berries, bool hasBoomerang, bool hasRunningShoes, bool runningShoesActivated);

	std::string currentLevel = "";
	int caughtPokemon = 0;
	int highScore = 0;
	int health = 0;
	int pokeBalls = 0;
	int berries = 0;
	bool hasBoomerang = false;
	bool hasRunningShoes = false;
	bool runningShoesActivated = false;
};