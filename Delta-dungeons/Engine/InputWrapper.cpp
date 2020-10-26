#include "InputWrapper.h"
#include <iostream>


InputWrapper::InputWrapper() {}

InputWrapper::InputWrapper(const cbFunction f, void* p) :func(f), pointer(p) {}

InputWrapper::~InputWrapper() {}

void InputWrapper::handleInput()
{
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			handleKeyPressed();
			break;
		case SDL_QUIT:
			func(pointer, KEY_ESC, KEY_PRESSED);
			break;
		case SDL_KEYUP:
			handleKeyReleased();
			break;

		}
	}
}

void InputWrapper::handleKeyPressed()
{
	switch (event.key.keysym.sym)
	{
	case SDLK_UP:
		func(pointer, KEY_UP, KEY_PRESSED);
		break;
	case SDLK_DOWN:
		func(pointer, KEY_DOWN, KEY_PRESSED);
		break;
	case SDLK_LEFT:
		func(pointer, KEY_LEFT, KEY_PRESSED);
		break;
	case SDLK_RIGHT:
		func(pointer, KEY_RIGHT, KEY_PRESSED);
		break;
	case SDLK_w:
		func(pointer, KEY_W, KEY_PRESSED);
		break;
	case SDLK_a:
		func(pointer, KEY_A, KEY_PRESSED);
		break;
	case SDLK_s:
		func(pointer, KEY_S, KEY_PRESSED);
		break;
	case SDLK_d:
		func(pointer, KEY_D, KEY_PRESSED);
		break;
	case SDLK_q:
		func(pointer, KEY_Q, KEY_PRESSED);
		break;
	case SDLK_e:
		func(pointer, KEY_E, KEY_PRESSED);
		break;
	default:
		break;
	}
}

void InputWrapper::handleKeyReleased()
{
	if (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				func(pointer, KEY_UP, KEY_RELEASED);
				break;
			case SDLK_DOWN:
				func(pointer, KEY_DOWN, KEY_RELEASED);
				break;
			case SDLK_LEFT:
				func(pointer, KEY_LEFT, KEY_RELEASED);
				break;
			case SDLK_RIGHT:
				func(pointer, KEY_RIGHT, KEY_RELEASED);
				break;
			case SDLK_w:
				func(pointer, KEY_W, KEY_RELEASED);
				break;
			case SDLK_a:
				func(pointer, KEY_A, KEY_RELEASED);
				break;
			case SDLK_s:
				func(pointer, KEY_S, KEY_RELEASED);
				break;
			case SDLK_d:
				func(pointer, KEY_D, KEY_RELEASED);
				break;
			case SDLK_q:
				func(pointer, KEY_Q, KEY_RELEASED);
				break;
			case SDLK_e:
				func(pointer, KEY_E, KEY_RELEASED);
				break;
			default:
				break;
			}
		}
	}
}

void InputWrapper::mapKeyBindings(const KeyCodes code) {}