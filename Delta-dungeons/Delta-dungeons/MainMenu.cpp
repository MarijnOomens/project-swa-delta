#include "MainMenu.h"

MainMenu::MainMenu() {};
MainMenu::MainMenu(std::string txt, Vector2D textLoc, std::vector<Button> bttns) {
	text = txt;
	textLocation = textLoc;
	buttons = bttns;
};
MainMenu::~MainMenu() {};

void MainMenu::startGame() {};
void MainMenu::openCreditScreen() {};