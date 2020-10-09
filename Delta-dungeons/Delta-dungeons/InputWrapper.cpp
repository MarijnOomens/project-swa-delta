#include "InputWrapper.h"
#include <iostream>

InputWrapper::InputWrapper() {}

InputWrapper::InputWrapper(const cbFunction f):func(f){}

InputWrapper::~InputWrapper() {};

void InputWrapper::handleEvents() {
	bool isRunning = true;
	while (isRunning) {
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				std::cout << "up is pressed" << std::endl;
				func(KEY_UP);
				break;
			case SDLK_DOWN:
				std::cout << "down is pressed" << std::endl;
				func(KEY_DOWN);
				break;
			case SDLK_LEFT:
				std::cout << "left is pressed" << std::endl;
				func(KEY_LEFT);
				break;
			case SDLK_RIGHT:
				std::cout << "right is pressed" << std::endl;
				func(KEY_RIGHT);
				break;
			case SDLK_q:
				std::cout << "Q is pressed" << std::endl;
				func(KEY_Q);
				break;
			default:
				break;
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				/*std::cout << "up is released" << std::endl;*/
				break;
			case SDLK_DOWN:
				/*std::cout << "down is released" << std::endl;*/
				break;
			case SDLK_LEFT:
				/*std::cout << "left is released" << std::endl;*/
				break;
			case SDLK_RIGHT:
				/*std::cout << "right is released" << std::endl;*/
				break;
			case SDLK_q:
				/*std::cout << "Q is released" << std::endl;*/
				break;
			default:
				break;
			}
		}
	}
}

void InputWrapper:: mapKeyBindings(const Keycodes code)
{

}

