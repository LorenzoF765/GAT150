#include "AudioChannel.h"
#include <fmod.hpp>

namespace Engine
{
	bool AudioChannel::IsPlaying()
	{
		// !! if channel is null, return false 
		if (channel_ == nullptr) return false;

		bool isPlaying;
		channel_->isPlaying(&isPlaying);

		return isPlaying;
	}

	void AudioChannel::Stop()
	{
		if (IsPlaying()) channel_->stop();
	}

	void AudioChannel::SetPitch(float pitch)
	{
		if (IsPlaying())
		{
			channel_->setPitch(pitch);
		}// !! call setPitch on channel (pass pitch) 
	}

	float AudioChannel::GetPitch()
	{
		float pitch = 0;
		if (IsPlaying())
		{
			channel_->getPitch(&pitch);
		}// !! call getPitch (pass pointer to pitch &) 

		return pitch;
	}

	void AudioChannel::SetVolume(float volume)
	{
		if (IsPlaying())
		{
			channel_->setVolume(volume);
		}// !! call setVolume on channel (pass volume) 
	}

	float AudioChannel::GetVolume()
	{
		float volume = 0;
		if (IsPlaying())
		{
			channel_->getVolume(&volume);
		}// !! call getVolume (pass pointer to volume &) 

		return volume;
	}
}