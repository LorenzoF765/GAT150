#include "PhysicsComponent.h"
#include "Engine.h"

namespace Engine
{
	void PhysicsComponent::Update()
	{
		velocity_ += acceleration_ * timer_g.deltaTime;
		owner_->transform_.position += velocity_ * timer_g.deltaTime;
		velocity_ *= damping;

		acceleration_ = Vector2::Zero;
	}
	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, damping);
		READ_DATA(value, velocity_);
		READ_DATA(value, acceleration_);

		return true;
	}
}

