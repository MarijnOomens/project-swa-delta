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

void GameState::save()
{
	saveSystem.save(currentState);
}

void GameState::load()
{
	currentState = saveSystem.load();
}
