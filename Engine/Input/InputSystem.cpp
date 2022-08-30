#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace Engine
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_esc = SDL_SCANCODE_ESCAPE;
	const uint32_t key_shift = SDL_SCANCODE_LSHIFT;

	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;

	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys_); // Returns a snapshot of the current keyboard state

		keyBoardState_.resize(numKeys_);
		std::copy(keyboardState, keyboardState + numKeys_, keyBoardState_.begin());

		prevkeyBoardState_ = keyBoardState_;
	}
	void InputSystem::ShutDown()
	{

	}
	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		// Saves Previous Keyboard State
		prevkeyBoardState_ = keyBoardState_;

		//Get Current Keyboard State
		const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys_);
		std::copy(keyboardState, keyboardState + numKeys_, keyBoardState_.begin());

		// Saves Previous Mouse State
		prevMouseButtonState_ = mouseButtonState_;

		//Get Current Mouse Button State
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		mousePosition_ = Engine::Vector2{ x, y };
		mouseButtonState_[0] = buttons & SDL_BUTTON_LMASK;
		mouseButtonState_[1] = buttons & SDL_BUTTON_MMASK;
		mouseButtonState_[2] = buttons & SDL_BUTTON_RMASK;
	}

	InputSystem::KeyState InputSystem::GetKeyState(uint32_t key)
	{
		KeyState keystate = KeyState::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);

		if (keyDown == 0 && prevKeyDown == 0)
		{
			keystate = KeyState::Idle;
		}

		if (keyDown == 1 && prevKeyDown == 0)
		{
			keystate = KeyState::Pressed;
		}

		if (keyDown == 1 && prevKeyDown == 1)
		{
			keystate = KeyState::Held;
		}

		if (keyDown == 0 && prevKeyDown == 1)
		{
			keystate = KeyState::Released;
		}

		return keystate;
	}
	InputSystem::KeyState InputSystem::GetButtonState(uint32_t button)
	{
		KeyState mouseButtonState_ = KeyState::Idle;

		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (buttonDown == 0 && prevButtonDown == 0)
		{
			mouseButtonState_ = KeyState::Idle;
		}

		if (buttonDown == 1 && prevButtonDown == 0)
		{
			mouseButtonState_ = KeyState::Pressed;
		}

		if (buttonDown == 1 && prevButtonDown == 1)
		{
			mouseButtonState_ = KeyState::Held;
		}

		if (buttonDown == 0 && prevButtonDown == 1)
		{
			mouseButtonState_ = KeyState::Released;
		}

		return mouseButtonState_;
	}
}
