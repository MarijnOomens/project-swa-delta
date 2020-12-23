#pragma once
#include <string>
#include "SaveSystem.h"
#include "GameStateObject.h"

class GameState
{
public:
	static GameState& getInstance();

	void reset();
	void addCaughPokemon(int amount);
	int getCaughtPokemon();
	int getHighScore();
	void setHealth(int h);
	int getHealth();
	void setPokeballs(int p);
	void save();
	void load();

private:
	static GameState gameState;
	GameState() {};

	SaveSystem saveSystem;

	GameStateObject currentState;
};
