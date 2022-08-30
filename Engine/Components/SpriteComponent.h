#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"
#include "Serialization/Json.h"

namespace Engine
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:

		CLASS_DECLARATION(SpriteComponent)

			virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		virtual void Initialize() override {}

		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);

		std::shared_ptr<Texture> texture_;
	};
}