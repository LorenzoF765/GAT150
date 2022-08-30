#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"

namespace Engine
{
	class AudioComponent : public Component
	{
	public:

		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

			virtual void Initialize() override;
		void Update() override;

		void Play();
		void Stop();

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		AudioChannel channel_;
		std::string soundName_;
		float volume_{ 1 };
		float pitch_{ 1 };
		bool playOnAwake_{ false };
		bool loop_{ false };
	};
}