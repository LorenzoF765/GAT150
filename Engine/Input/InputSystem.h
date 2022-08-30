#pragma once
#include "../Math/Vector2.h"
#include <cstdint>
#include <vector>
#include <map>
#include <array>
#include <string>

namespace Solas {



	class InputSystem {
	public:
		enum KeyState {
			Idle,
			Pressed,
			Held,
			Released
		};
	public:

		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		KeyState GetKeyState(uint32_t key);
		bool GetKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool GetPrevKeyDown(uint32_t key) { return m_prevKeyboardState[key]; }

		const Vector2& GetMousePos() const { return m_mousePos; }

		KeyState GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPrevButtonDown(uint32_t button) { return m_prevMouseButtonState[button]; }

		bool onKeyLeft(Solas::InputSystem::KeyState state);
		bool onKeyRight(Solas::InputSystem::KeyState state);
		bool onKeyUp(Solas::InputSystem::KeyState state);
		bool onKeyDown(Solas::InputSystem::KeyState state);

		bool onKeyEsc(Solas::InputSystem::KeyState state);
		bool onKeySpace(Solas::InputSystem::KeyState state);

		bool onRightClick(Solas::InputSystem::KeyState state);
		bool onLeftClick(Solas::InputSystem::KeyState state);
	private:
		int m_numKeys;

		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;

		Vector2 m_mousePos;
		std::array<uint8_t, 3>m_mouseButtonState;
		std::array<uint8_t, 3>m_prevMouseButtonState;
	};

	//extern means you want to declare it but not define it.
	extern const uint32_t key_space;
	extern const uint32_t key_W;
	extern const uint32_t key_S;
	extern const uint32_t key_A;
	extern const uint32_t key_D;
	extern const uint32_t key_esc;

	//mouse
	extern const uint32_t buttonLeft;
	extern const uint32_t buttonMiddle;
	extern const uint32_t buttonRight;
}