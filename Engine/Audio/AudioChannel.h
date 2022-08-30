#pragma once
#include "../ThirdParty/fmod/core/inc/fmod.hpp"

namespace FMOD
{
	class FMOD::Channel;
}

namespace Engine
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) { channel_ = channel; }// !! set m_channel 

		bool IsPlaying();
		void Stop();

		void SetPitch(float pitch);
		float GetPitch();

		void SetVolume(float volume);
		float GetVolume();

	private:
		FMOD::Channel* channel_ = nullptr;
	};

}