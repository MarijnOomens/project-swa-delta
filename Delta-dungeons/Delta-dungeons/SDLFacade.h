#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "DrawController.h"
#include "FrameManager.h"
#include "Renderer.h"
class SDLFacade {
public:
	SDLFacade();
	~SDLFacade();

	DrawController* drawController;
	FrameManager* frameManager;
	Renderer* renderer;
	std::string constructorError() const noexcept;

	SDL_Texture* loadTexture(const std::string* path);
	void drawTexture(const char* path, const Vector2D source2D, const Vector2D destination2D);
	void setFrameStart();
	void setFrameDelay();
	void update(std::list<GameObject> gameObjects);
	void render(std::list<GameObject> gameObjects);
	void initRenderer(const char* title, const int width, const int height, const bool fullscreen);
	void clean();
	void init();
private: 
};