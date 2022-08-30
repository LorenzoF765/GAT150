#pragma once
#include "Framework/Component.h"

namespace Solas {
	class Renderer;

	class RendererComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}