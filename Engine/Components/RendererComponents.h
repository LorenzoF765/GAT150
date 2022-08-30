#pragma once
#include "Framework/Components.h"

namespace Solas
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:

		virtual void Draw(Renderer& renderer) = 0;
	};
}
