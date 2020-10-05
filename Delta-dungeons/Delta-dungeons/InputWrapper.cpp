#include "InputWrapper.h"

void InputWrapper::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		//Renderer::stop;		
		break;
	default:
		break;
	}
}