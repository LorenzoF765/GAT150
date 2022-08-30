#pragma once
#include "../Math//Vector2.h"
#include <cstdint>
#include <vector>
#include <map>
#include <array>
#include <string>

namespace Engine
{
	class InputSystem
	{
	public:

		enum KeyState
		{
			Idle, Pressed, Held, Released
		};

		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void ShutDown();

		void Update();

		bool GetKeyDown(int key) { return keyBoardState_[key]; }

		KeyState GetKeyState(uint32_t key);
		bool GetKeyDown(uint32_t key) { return keyBoardState_[key]; }
		bool GetPreviousKeyDown(uint32_t key) { return prevkeyBoardState_[key]; }

		const Vector2& GetMousePosition() const { return mousePosition_; }

		KeyState GetButtonState(uint32_t button);

		bool GetButtonDown(uint32_t button) { return mouseButtonState_[button]; }
		bool GetPreviousButtonDown(uint32_t button) { return prevMouseButtonState_[button]; }

	private:

		int numKeys_;

		std::vector<uint8_t> keyBoardState_;
		std::vector<uint8_t> prevkeyBoardState_;

		Vector2 mousePosition_;
		std::array<uint32_t, 3> mouseButtonState_;
		std::array<uint32_t, 3> prevMouseButtonState_;
	};

	extern const uint32_t key_space;
	extern const uint32_t key_esc;
	extern const uint32_t key_shift;

	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;

	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
}
