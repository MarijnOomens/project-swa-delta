#include "InputWrapper.h"
#include <iostream>

InputWrapper::InputWrapper() {}

InputWrapper::InputWrapper(const cbFunction f) :func(f) {}

InputWrapper::~InputWrapper() {};

void InputWrapper::handleKeyPressed() {
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			func(KEY_UP, KEY_PRESSED);
			break;
		case SDLK_DOWN:
			func(KEY_DOWN, KEY_PRESSED);
			break;
		case SDLK_LEFT:
			func(KEY_LEFT, KEY_PRESSED);
			break;
		case SDLK_RIGHT:
			func(KEY_RIGHT, KEY_PRESSED);
			break;
		case SDLK_w:
			func(KEY_W, KEY_PRESSED);
			break;
		case SDLK_a:
			func(KEY_A, KEY_PRESSED);
			break;
		case SDLK_s:
			func(KEY_S, KEY_PRESSED);
			break;
		case SDLK_d:
			func(KEY_D, KEY_PRESSED);
			break;
		case SDLK_q:
			func(KEY_Q, KEY_PRESSED);
			break;
		case SDLK_e:
			func(KEY_E, KEY_PRESSED);
			break;
		default:
			break;
		}
	}
}

void InputWrapper::handleKeyReleased() {
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			func(KEY_UP, KEY_RELEASED);
			break;
		case SDLK_DOWN:
			func(KEY_DOWN, KEY_RELEASED);
			break;
		case SDLK_LEFT:
			func(KEY_LEFT, KEY_RELEASED);
			break;
		case SDLK_RIGHT:
			func(KEY_RIGHT, KEY_RELEASED);
			break;
		case SDLK_w:
			func(KEY_W, KEY_RELEASED);
			break;
		case SDLK_a:
			func(KEY_A, KEY_RELEASED);
			break;
		case SDLK_s:
			func(KEY_S, KEY_RELEASED);
			break;
		case SDLK_d:
			func(KEY_D, KEY_RELEASED);
			break;
		case SDLK_q:
			func(KEY_Q, KEY_RELEASED);
			break;
		case SDLK_e:
			func(KEY_E, KEY_RELEASED);
			break;
		default:
			break;
		}
	}
}

void InputWrapper::mapKeyBindings(const KeyCodes code)
{

}

