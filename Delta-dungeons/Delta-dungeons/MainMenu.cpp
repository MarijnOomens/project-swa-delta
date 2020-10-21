#include "MainMenu.h"

MainMenu::MainMenu() {
	//HARDCODE DIE SHIT
	/*Button start = new Button();*/
	text = "Delta Dungeons";
	textLocation = new Vector2D(100, 100);
};
MainMenu::MainMenu(GraphicsComponent* gcmm) {
	gc = gcmm;
	gc->SetTexture("mainmenu");
};

MainMenu::~MainMenu() {};

void MainMenu::startGame() {};
void MainMenu::openCreditScreen() {};
void MainMenu::closeScreen() {};

void MainMenu::connectCallback() {};
void MainMenu::callbackFunction() {};

void MainMenu::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {

}