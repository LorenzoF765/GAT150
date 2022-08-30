#pragma once
#include "Framework/Component.h"
#include <string>

namespace Solas {
	class AudioComponent : public Component {
	public:
		AudioComponent() = default;
		~AudioComponent() = default;

		void Update() override;

		void Play();
		void Stop();

		//Variables
		std::string m_soundName;
		bool m_playOnAwake = false;
		bool m_loop = false;
		float m_volume = 1;
		float m_pitch = 1;
	};
}