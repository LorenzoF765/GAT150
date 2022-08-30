#include "AudioComponent.h"
#include "Engine.h"

namespace Engine
{
	AudioComponent::~AudioComponent()
	{
		Stop();
	}
	void AudioComponent::Initialize()
	{
		if (playOnAwake_)
		{
			Play();
		}
	}
	void AudioComponent::Update()
	{
	}
	void AudioComponent::Play()
	{
		Stop();
		channel_ = audioSystem_g.PlayAudio(soundName_, loop_);
	}
	void AudioComponent::Stop()
	{
		channel_.Stop();
	}
	bool AudioComponent::Write(const rapidjson::Value& value)const { return true; }
	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, soundName_);
		READ_DATA(value, volume_);
		READ_DATA(value, pitch_);
		READ_DATA(value, playOnAwake_);
		READ_DATA(value, loop_);

		audioSystem_g.AddAudio(soundName_, soundName_);

		return true;
	}
}
