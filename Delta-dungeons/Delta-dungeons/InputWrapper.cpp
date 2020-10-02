#include "InputWrapper.h"
#include "Window.h"

void InputWrapper::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Window::stop;		
		break;
	default:
		break;
	}
}