#include "GameStateObject.h"

GameStateObject::GameStateObject(const std::string& lvl, int caughtPokemon, int highScore, int health, int pokeBalls, int berries, bool hasBoomerang, bool hasRunningShoes, bool runningShoesActivated) 
	: currentLevel(lvl), caughtPokemon(caughtPokemon), highScore(highScore), health(health), pokeBalls(pokeBalls), berries(berries), hasBoomerang(hasBoomerang), hasRunningShoes(hasRunningShoes), runningShoesActivated(runningShoesActivated)
{

}