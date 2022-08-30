#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace Solas {
	void PlayerComponent::Update() {
		Vector2 direction = Vector2::zero;
		if (Solas::inputSystem_g.GetKeyState(key_A) == Solas::InputSystem::Held) {
			//m_owner->transform_.position += {-10, 0};
			//direction = Vector2::left;
			m_owner->transform_.rotation -= 100 * time_g.deltaTime;
		}

		if (Solas::inputSystem_g.GetKeyState(key_D) == Solas::InputSystem::Held) {
			//m_owner->transform_.position += {10, 0};
			//direction = Vector2::right;
			m_owner->transform_.rotation += 100 * time_g.deltaTime;
		}

		float thrust = 0;
		if (Solas::inputSystem_g.GetKeyState(key_W) == Solas::InputSystem::Held) {
			//m_owner->transform_.position += {0, -10};
			thrust = 100;
		}


		if (Solas::inputSystem_g.GetKeyState(key_S) == Solas::InputSystem::Held) {
			//m_owner->transform_.position += {0, 10};
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->transform_.rotation)) * thrust;
			component->ApplyForce(force);

			/*force = (Vector2{ 400, 300 } - m_owner->transform_.position).Normalized() * 60.0f;
			component->ApplyForce(force);*/
		}

		m_owner->transform_.position += direction * 300 * time_g.deltaTime;

		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed) {
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component) {
				component->Play();
			}
		}
	}
}
