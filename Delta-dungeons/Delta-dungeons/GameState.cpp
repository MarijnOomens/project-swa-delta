#include "GameState.h"

GameState GameState::gameState;

GameState& GameState::getInstance()
{
	return gameState;
}

void GameState::reset()
{
	currentState = GameStateObject("Level1", 0, 0, 5, 20, 0, false, false, false);
}

void GameState::addCaughtPokemon(int amount)
{
	this->currentState.caughtPokemon += amount;
	if (currentState.caughtPokemon > currentState.highScore)
	{
		currentState.highScore = currentState.caughtPokemon;
	}
}

std::string GameState::getCurrentLevel() const
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

int GameState::getHighScore() const
{
	return currentState.highScore;
}

void GameState::setHealth(int h)
{
	currentState.health = h;
}

int GameState::getHealth() const
{
	return currentState.health;
}

void GameState::setPokeballs(int p)
{
	currentState.pokeBalls = p;
}

int GameState::getPokeballs() const
{
	return currentState.pokeBalls;
}

void GameState::setBerries(int b)
{
	currentState.berries = b;
}

int GameState::getBerries() const
{
	return currentState.berries;
}

bool GameState::getHasBoomerang() const
{
	return currentState.hasBoomerang;
}

void GameState::setHasBoomerang(bool hasBoomerang)
{
	currentState.hasBoomerang = hasBoomerang;
}

bool GameState::getHasRunningShoes() const
{
	return currentState.hasRunningShoes;
}

void GameState::setHasRunningShoes(bool hasRunningShoes)
{
	currentState.hasRunningShoes = hasRunningShoes;
}

bool GameState::getRunningShoesActivated() const
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

void GameState::setIsPaused()
{
	isPaused = !isPaused;
}

void GameState::setIsPaused(bool paused)
{
	isPaused = paused;
}

bool GameState::getIsPaused() const
{
	return isPaused;
}

void GameState::setIsInputPaused(bool paused)
{
	isInputPaused = paused;
}

bool GameState::getIsInputPaused() const
{
	return isInputPaused;
}