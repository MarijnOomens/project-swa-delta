#include "InputWrapper.h"
#include <iostream>
/// <summary>
/// Inputwrapper is a class which holds what the inputs are supposed to do.
/// </summary>
InputWrapper::InputWrapper() {}

InputWrapper::InputWrapper(const cbFunction f, void* p) :func(f), pointer(p) {}

InputWrapper::~InputWrapper() {}


/// <summary>
/// The handleInput calls the input based on which keyevent is called.
/// </summary>
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
			func(pointer, KeyCodes::KEY_ESC, KeyboardEvent::KEY_PRESSED);
			break;
		case SDL_KEYUP:
			handleKeyReleased();
			break;

		}
	}
}

/// <summary>
/// The handleInput calls the input based on which key is pressed
/// </summary>
void InputWrapper::handleKeyPressed()
{
	switch (event.key.keysym.sym)
	{
	case SDLK_UP:
		func(pointer, KeyCodes::KEY_UP, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_DOWN:
		func(pointer, KeyCodes::KEY_DOWN, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_LEFT:
		func(pointer, KeyCodes::KEY_LEFT, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_RIGHT:
		func(pointer, KeyCodes::KEY_RIGHT, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_w:
		func(pointer, KeyCodes::KEY_W, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_a:
		func(pointer, KeyCodes::KEY_A, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_s:
		func(pointer, KeyCodes::KEY_S, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_d:
		func(pointer, KeyCodes::KEY_D, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_q:
		func(pointer, KeyCodes::KEY_Q, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_e:
		func(pointer, KeyCodes::KEY_E, KeyboardEvent::KEY_PRESSED);
		break;
	case SDLK_BACKSPACE:
		func(pointer, KeyCodes::KEY_BACKSPACE, KeyboardEvent::KEY_PRESSED);
		break;
	default:
		break;
	}
}


/// <summary>
/// The handleInput calls the input based on which key is released
/// </summary>
void InputWrapper::handleKeyReleased()
{
	switch (event.key.keysym.sym)
	{
	case SDLK_UP:
		func(pointer, KeyCodes::KEY_UP, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_DOWN:
		func(pointer, KeyCodes::KEY_DOWN, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_LEFT:
		func(pointer, KeyCodes::KEY_LEFT, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_RIGHT:
		func(pointer, KeyCodes::KEY_RIGHT, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_w:
		func(pointer, KeyCodes::KEY_W, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_a:
		func(pointer, KeyCodes::KEY_A, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_s:
		func(pointer, KeyCodes::KEY_S, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_d:
		func(pointer, KeyCodes::KEY_D, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_q:
		func(pointer, KeyCodes::KEY_Q, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_e:
		func(pointer, KeyCodes::KEY_E, KeyboardEvent::KEY_RELEASED);
		break;
	case SDLK_BACKSPACE:
		func(pointer, KeyCodes::KEY_BACKSPACE, KeyboardEvent::KEY_RELEASED);
		break;
	default:
		break;
	}
}

void InputWrapper::mapKeyBindings(const KeyCodes code) {}