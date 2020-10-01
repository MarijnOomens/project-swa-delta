#pragma once
#include <vector>
#include <string>

class UIManager {

public:
	void playDialogue(std::vector<std::string>);
	void updateHudHealth(int);
	void updateHudCollectedCrystals(int);
	void updateHightScore(int)
};