#pragma once

class HUD 
{

private:
	int health;
	int collectedCrystals;
	int highScore;

	void updateHealth(int);
	void updateCollectedCrystals(int);
	void updateHighScore(int);

};