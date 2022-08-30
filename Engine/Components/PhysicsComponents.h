#pragma once

#include "Framework/Components.h"
#include "Math/Vector2.h"

namespace Solas {
	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;
		~PhysicsComponent() = default;

		void Update() override;

		void ApplyForce(const Vector2& force) {
			m_acceleration += force;
		}

		//Variables
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_damping = 1;
	};
}