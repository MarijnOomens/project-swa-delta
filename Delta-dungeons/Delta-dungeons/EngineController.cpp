#include "EngineController.h"
#include "Button.h"
#include <vector>
#include "GraphicsComponent.h"

EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>();
	assetManager = std::make_shared<AssetManager>();

	// DEBUG
	assetManager->addTexture("button_play", "Assets/button_play.png");
	GraphicsComponent* gc = new GraphicsComponent();
	Button* button = new Button(300, 250, { "button_play", "button_play_hover" }, gc);
	// END DEBUG

	behaviourObjects.emplace_back(button);
	initRenderer("delta dungeons", 800, 600, false);
	StartGame();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {
	
};

void EngineController::Update(std::list<std::shared_ptr<BehaviourObject>>& bhObjects) {
	for(auto& bo : bhObjects)
	{
		bo.get()->Update();
	}
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::renderFacade->init(title, width, height, fullscreen);
};

void EngineController::StartGame() {

	while (renderFacade->renderer->isRunning) {
		renderFacade->setFrameStart();

		EngineController::Update(behaviourObjects);
		//change the values 
		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
