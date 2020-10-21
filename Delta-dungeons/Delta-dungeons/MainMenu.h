#pragma once
#include "Screen.h"
#include <string>
#include <vector>
#include "Button.h"
#include "Color.h"
#include "GraphicsComponent.h"

class MainMenu : public Screen, public GameObject
{
public:
	MainMenu(); //yes or no
	MainMenu(GraphicsComponent* gcmm);
	~MainMenu();

	Screen* creditScreen;
	void startGame();
	void openCreditScreen();

	void closeScreen() override;

	void connectCallback() override;
	void callbackFunction() override;
	void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) override;

	std::vector<BehaviourObject> getBehaviourObjects() override;
};