#include "MainMenu.h"

MainMenu::MainMenu() {
	//HARDCODE DIE SHIT
	text = "Delta Dungeons";
	//textLocation = new Vector2D(100, 100);
};

MainMenu::MainMenu(GraphicsComponent* gcmm) {
	gc = gcmm;
	gc->setTexture("mainmenu");
	gc->imageDimensions = { 1024, 768 };

	//Maak hashmappie voor textures
	//En daarna mooie buttons enzo
	//yeet

	/*engineFacade->addTexture("button_play", "Assets/button_play.png");
	GraphicsComponent* gc = new GraphicsComponent();
	gc->addTextureManager(textureManager);
	behaviourObjects.emplace_back(gc);
	Button* button = new Button(300, 400, { "button_play", "button_play_hover" }, gc);
	behaviourObjects.emplace_back(button);*/
};

MainMenu::~MainMenu() {};

void MainMenu::startGame() {};
void MainMenu::openCreditScreen() {};
void MainMenu::closeScreen() {};

void MainMenu::connectCallback() {};
void MainMenu::callbackFunction() {};
void MainMenu::update() {};

void MainMenu::handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) {

}

std::vector<BehaviourObject> MainMenu::getBehaviourObjects() {
	std::vector<BehaviourObject> list;
	return list;
}