#pragma once
#include "Framework/Component.h"

namespace Solas {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Update() override;
	};
}