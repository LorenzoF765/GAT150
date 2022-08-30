#include "PhysicsComponents.h"
#include "Engine.h"

namespace Solas {
	void PhysicsComponent::Update() {
		m_velocity += m_acceleration * timer_g.deltaTime;
		m_owner->transform_.position += m_velocity * timer_g.deltaTime;
		m_velocity *= m_damping;

		m_acceleration = Vector2::zero;
	}
}