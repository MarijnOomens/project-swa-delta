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

	SDL_Texture* loadTexture(const char* path);
	void drawTexture(const char* path, Vector2D source2D, Vector2D destination2D);
	void setFrameStart();
	void setFrameDelay();
	void render(std::list<GameObject> gameObjects);
	void initRenderer(const char* title, int width, int height, bool fullscreen);
	void clean();
	void init();
private: 
};