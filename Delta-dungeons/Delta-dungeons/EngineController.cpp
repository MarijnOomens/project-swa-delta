#include "EngineController.h"
#include "Button.h"
#include <vector>
#include "GraphicsComponent.h"

EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>(renderFacade);
	assetManager = std::make_shared<AssetManager>();

	initRenderer("delta dungeons", 800, 600, false);
	StartGame();
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

SDL_Event evt;

void EngineController::StartGame() {

	while (renderFacade->renderer->isRunning) {

		SDL_WaitEvent(&evt);
		if (evt.type == SDL_QUIT)
			renderFacade->renderer.get()->stop();

		renderFacade->setFrameStart();
		renderFacade->beforeFrame();

		EngineController::Update(behaviourObjects);
		
		renderFacade->afterFrame();
		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
