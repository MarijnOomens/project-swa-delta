#include "GameState.h"

GameState GameState::gameState;

GameState& GameState::getInstance()
{
	return gameState;
}

void GameState::reset()
{
	currentState = GameStateObject("Level1", 0, 0, 5, 20, 0, false, true, false);
}

void GameState::addCaughPokemon(int amount)
{
	this->currentState.caughtPokemon += amount;
	if (currentState.caughtPokemon > currentState.highScore)
	{
		currentState.highScore = currentState.caughtPokemon;
	}
}

std::string GameState::getCurrentLevel()
{
	return currentState.currentLevel;
}

void GameState::setCurrentLevel(const std::string& cl)
{
	currentState.currentLevel = cl;
}

int GameState::getCaughtPokemon()
{
	return currentState.caughtPokemon;
}

int GameState::getHighScore()
{
	return currentState.highScore;
}

void GameState::setHealth(int h)
{
	currentState.health = h;
}

int GameState::getHealth()
{
	return currentState.health;
}

void GameState::setPokeballs(int p)
{
	currentState.pokeBalls = p;
}

int GameState::getPokeballs()
{
	return currentState.pokeBalls;
}

void GameState::setBerries(int b)
{
	currentState.berries = b;
}

int GameState::getBerries()
{
	return currentState.berries;
}

bool GameState::getHasBoomerang()
{
	return currentState.hasBoomerang;
}

void GameState::setHasBoomerang(bool hasBoomerang) 
{
	currentState.hasBoomerang = hasBoomerang;
}

bool GameState::getHasRunningShoes()
{
	return currentState.hasRunningShoes;
}

void GameState::setHasRunningShoes(bool hasRunningShoes)
{
	currentState.hasRunningShoes = hasRunningShoes;
}

bool GameState::getRunningShoesActivated()
{
	return currentState.runningShoesActivated;
}

void GameState::setRunningShoesActivated(bool runningShoesActivated)
{
	currentState.runningShoesActivated = runningShoesActivated;
}

void GameState::save()
{
	saveSystem.save(currentState);
}

void GameState::load()
{
	currentState = saveSystem.load();
}
