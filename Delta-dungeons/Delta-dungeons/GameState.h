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
	std::string getCurrentLevel();
	void setCurrentLevel(const std::string& cl);
	int getCaughtPokemon();
	int getHighScore();
	int getHealth();
	void setHealth(int h);
	int getPokeballs();
	void setPokeballs(int p);
	int getBerries();
	void setBerries(int b);
	bool getHasBoomerang();
	void setHasBoomerang(bool hasBoomerang);	
	bool getHasRunningShoes();
	void setHasRunningShoes(bool hasRunningShoes);	
	bool getRunningShoesActivated();
	void setRunningShoesActivated(bool runningShoesActivated);
	void save();
	void load();

private:
	static GameState gameState;
	GameState() {};

	SaveSystem saveSystem;

	GameStateObject currentState;
};
