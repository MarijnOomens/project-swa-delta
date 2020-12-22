#include "GameState.h"

GameState GameState::gameState;

GameState& GameState::getInstance()
{
	return gameState;
}

void GameState::reset()
{
	currentLevel = "Level1";
	caughtPokemon = 0;
	health = 5;
	pokeBalls = 20;
	berries = 0;
	hasBoomerang = false;
	hasRunningShoes = true;
	runningShoesActivated = false;
}

void GameState::addCaughPokemon(int amount)
{
	this->caughtPokemon += amount;
	if (caughtPokemon > highScore)
	{
		highScore = caughtPokemon;
	}
}

int GameState::getCaughtPokemon()
{
	return caughtPokemon;
}

int GameState::getHighScore()
{
	return highScore;
}

void GameState::save()
{
	saveSystem.save(currentLevel, caughtPokemon, health, pokeBalls, berries, hasBoomerang, hasRunningShoes, runningShoesActivated);
}
