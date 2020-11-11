#pragma once

#include "SDL.h"
#include "main.h"
#include "DrawController.h"
#include "FrameManager.h"
#include "Renderer.h"
#include "Vector2D.h"
#include <iostream>
#include <vector>
#include <map>
#include "Colour.h"

class RenderFacade 
{
public:
	std::shared_ptr<Renderer> renderer;

	RenderFacade();
	~RenderFacade() {}

	std::string constructorError() const noexcept;
	SDL_Texture* loadTexture(const std::string& imageLocation) const;

	void setFrameStart() const;
	void setFrameDelay() const;
	void drawTexture(const std::string& path, const std::string& text, const Colour& colour, const Transform& transform, int fontSize) const;
	void drawTexture(const std::string& path, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimensions, int row, int frames, int speed, bool animated, bool flipped, bool isScreen) const;
	void init(const std::string& title, int width, int height, bool fullscreen) const;
	void clean() const;
	void beforeFrame() const;
	void afterFrame() const;
	void createCamera(int x, int y) const;
	void quitGame() const;
	void pauseGame() const;
	void slowDownGame() const;
	void speedUpGame() const;
	void resetSpeedGame() const;

	std::tuple<int, int> passPlayerPosition(int x, int y) const;
	int getFPS() const;

private:
	std::unique_ptr<DrawController> drawController;
	std::unique_ptr<FrameManager> frameManager;
};