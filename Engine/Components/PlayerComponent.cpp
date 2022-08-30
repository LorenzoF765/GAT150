#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace Engine
{
	void PlayerComponent::Initialize()
	{
		auto component = owner_->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}
	void PlayerComponent::Update()
	{
		// Movement
		Vector2 direction = Vector2::Zero;
		if (inputSystem_g.GetKeyState(key_left) == InputSystem::Held)
		{
			direction = Vector2::Left;
		}
		if (inputSystem_g.GetKeyState(key_right) == InputSystem::Held)
		{
			direction = Vector2::Right;
		}

		auto component = owner_->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}
		// Shoot
		if (inputSystem_g.GetKeyState(key_space) == InputSystem::Pressed)
		{
			auto component = owner_->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::Up * 500);
			}
		}

		// Grav Swap
		if (inputSystem_g.GetKeyState(key_shift) == InputSystem::Pressed)
		{
			auto component = owner_->GetComponent<RBPhysicsComponent>();
			if (component)
			{
				component->GravitySwitch();
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}
	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			other->SetDestroy(true);
		}
		std::cout << "Player Enter" << std::endl;
	}
	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player Exit" << std::endl;
	}
}
