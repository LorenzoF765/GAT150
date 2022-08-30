#pragma once
#include <string>
#include <map>
#include "AudioChannel.h"

namespace FMOD
{
	class System;
	class Sound;
}

namespace Engine
{
	class AudioSystem
	{
	public:

		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void ShutDown();

		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		AudioChannel PlayAudio(const std::string& name, float volume = 1, float pitch = 1, bool loop = false);

	private:

		FMOD::System* fmodSystem_;
		std::map<std::string, FMOD::Sound*> sounds_;
	};
}
