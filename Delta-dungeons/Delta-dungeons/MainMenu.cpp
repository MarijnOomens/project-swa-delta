#include "MainMenu.h"

MainMenu::MainMenu() {
	this->textures.try_emplace("mainmenu", "Assets/mainmenu-1024x768.png");
	this->textures.try_emplace("button_play", "Assets/button_play.png");

	text = "Delta Dungeons";
	gc = std::make_shared<GraphicsComponent>();
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