#pragma once

class HUD
{
private:
	void updateHealth(int param);
	void updateCollectedCrystals(int param);
	void updateHighScore(int param);

private:
	int health;
	int collectedCrystals;
	int highScore;
};