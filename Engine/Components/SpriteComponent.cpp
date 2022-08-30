#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace Engine
{
	void SpriteComponent::Update()
	{
	}

	void SpriteComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(texture_, GetSource(), owner_->transform_);
	}

	bool SpriteComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool SpriteComponent::Read(const rapidjson::Value& value)
	{
		std::string texture_name;
		READ_DATA(value, texture_name);

		texture_ = resourceManager_g.Get<Texture>(texture_name, renderer_g);

		if (!READ_DATA(value, source))
		{
			source.x = 0;
			source.y = 0;
			source.w = (int)texture_->GetSize().x;
			source.h = (int)texture_->GetSize().y;
		}

		return true;
	}
}



