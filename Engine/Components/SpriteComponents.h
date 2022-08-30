#pragma once
#include "RendererComponents.h"

namespace Solas
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Texture> texture_;
	};
}