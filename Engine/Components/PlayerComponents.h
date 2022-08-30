#pragma once
#include "Framework/Components.h"

namespace Solas
{
	class PlayerComponent : public Component
	{
	public:

		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Update() override;
	};
}
