#pragma once
#include <string>
#include <map>
//Include the necessary includes

//Forward delcaration of FMOD name
namespace FMOD {
	class System;
	class Sound;
}
namespace Solas {
	class AudioSystem {
	public:
		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		void PlayAudio(const std::string& name, bool loop = false);
		void StopMusic();
	private:
		FMOD::System* m_fmodSystem;
		std::map<std::string, FMOD::Sound*>m_sounds;
	};
}