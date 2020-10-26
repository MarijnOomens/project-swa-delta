#include "MainMenu.h"

MainMenu::MainMenu() {
	text = "Delta Dungeons";
	gc = std::make_unique<GraphicsComponent>();
	gc->setTexture("mainmenu");
	gc->imageDimensions = { 1024, 768 };
	this->components.emplace_back(gc);

	//Maak hashmappie voor textures
	//En daarna mooie buttons enzo
	//yeet

	//engineFacade->addTexture("button_play", "Assets/button_play.png");
	//GraphicsComponent* gc = new GraphicsComponent();
	//objects.emplace_back(gc);
	//Button* button = new Button(300, 400, { "button_play", "button_play_hover" }, gc);
	//objects.emplace_back(button);
};

MainMenu::~MainMenu() {};

void MainMenu::startGame() {};
void MainMenu::openCreditScreen() {};
void MainMenu::closeScreen() {};