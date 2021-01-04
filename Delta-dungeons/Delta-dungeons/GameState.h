#pragma once
#include <string>
#include "SaveSystem.h"
#include "GameStateObject.h"

class GameState
{
public:
	static GameState& getInstance();

	void reset();
	void addCaughtPokemon(int amount);
	std::string getCurrentLevel() const;
	void setCurrentLevel(const std::string& cl);
	int getCaughtPokemon();
	int getHighScore() const;
	int getHealth() const;
	void setHealth(int h);
	int getPokeballs() const;
	void setPokeballs(int p);
	int getBerries() const;
	void setBerries(int b);
	bool getHasBoomerang() const;
	void setHasBoomerang(bool hasBoomerang);
	bool getHasRunningShoes() const;
	void setHasRunningShoes(bool hasRunningShoes);
	bool getRunningShoesActivated() const;
	void setRunningShoesActivated(bool runningShoesActivated);
	void save();
	void load();
	void setIsPaused();
	void setIsPaused(bool paused);
	bool getIsPaused() const;
	void setIsInputPaused(bool paused);
	bool getIsInputPaused() const;

private:
	static GameState gameState; 
	GameState() {}

	SaveSystem saveSystem;
	GameStateObject currentState;
	bool isPaused;
	bool isInputPaused;
};
