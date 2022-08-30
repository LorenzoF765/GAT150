#include "AudioSystem.h"
#include "Core/Logger.h"
#include <fmod.hpp>

namespace Engine
{
	void Engine::AudioSystem::Initialize()
	{
		FMOD::System_Create(&fmodSystem_);

		void* extradriverdata = nullptr;
		fmodSystem_->init(32, FMOD_INIT_NORMAL, extradriverdata);
	}

	void Engine::AudioSystem::ShutDown()
	{
		for (auto sound : sounds_)
		{
			sound.second->release();
		}

		sounds_.clear();
		fmodSystem_->close();
		fmodSystem_->release();
	}

	void Engine::AudioSystem::Update()
	{
		fmodSystem_->update();
	}

	void Engine::AudioSystem::AddAudio(const std::string& name, const std::string& filename)
	{
		auto it = sounds_.find(name);
		if (it == sounds_.end())
		{
			FMOD::Sound* sound = nullptr;
			fmodSystem_->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
			if (sound == nullptr)
			{
				LOG("Error: Could Not Create Sound from %s.", filename.c_str());
			}
			sounds_[name] = sound;
		}
	}

	AudioChannel AudioSystem::PlayAudio(const std::string& name, float volume, float pitch, bool loop)
	{
		// find sound in map 
		auto iter = sounds_.find(name);
		// if sound key not found in map (iter == end()), return default channel 
		if (iter == sounds_.end())
		{
			LOG("Error could not find sound %s.", name.c_str());
			return AudioChannel{};
		}

		// get sound pointer from iterator 
		FMOD::Sound* sound = iter->second;
		FMOD_MODE mode = (loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		sound->setMode(mode);

		// play sound, sets the pointer to the channel it is playing in 
		FMOD::Channel* channel;
		fmodSystem_->playSound(sound, 0, false, &channel);
		channel->setVolume(volume);
		channel->setPitch(pitch);
		channel->setPaused(false);

		// return audio channel with channel pointer set 
		return AudioChannel{ channel };
	}
}
