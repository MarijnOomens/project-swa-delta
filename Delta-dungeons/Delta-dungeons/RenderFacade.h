#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "DrawController.h"
#include "FrameManager.h"
#include "Renderer.h"
#include <map>

class RenderFacade {
public:
	RenderFacade();
	~RenderFacade();

	std::shared_ptr<DrawController> drawController;
	std::shared_ptr<FrameManager> frameManager;
	std::shared_ptr<Renderer> renderer;
	std::string constructorError() const noexcept;

	SDL_Texture* loadTexture(const std::string* imageLocation);
	SDL_Texture* loadFontTexture(const std::string* fontLocation, const std::string* color, const std::string* stringValue);
	void drawTexture(std::string path, const Vector2D& destination2D, const Vector2D& coordinates);
	void setFrameStart();
	void setFrameDelay();
	void update(std::list<GameObject> gameObjects);
	void render(std::list<std::shared_ptr<GameObject>> gameObjects);
	void init(const char* title, const int width, const int height, const bool fullscreen);
	void clean();
	void beforeFrame();
	void afterFrame();
private: 
};