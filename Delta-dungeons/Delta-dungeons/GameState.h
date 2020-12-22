#pragma once
#include <string>
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

class GameState
{
public:
	static GameState& getInstance();

	void reset();
	void addCaughPokemon(int amount);
	int getCaughtPokemon();
	int getHighScore();
	void Save();

private:
	static GameState gameState;
	GameState() {}

	rapidxml::xml_document<> saveDoc;

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
