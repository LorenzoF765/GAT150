#include "RBPhysicsComponent.h"
#include "Engine.h"

namespace Engine
{
	RBPhysicsComponent::~RBPhysicsComponent()
	{
		if (body_)
		{
			physics_g.DestroyBody(body_);
		}
	}

	void RBPhysicsComponent::Initialize()
	{
		body_ = physics_g.CreateBody(owner_->transform_.position, owner_->transform_.rotation, data);
		body_->SetGravityScale(data.gravity_scale);
		body_->SetLinearDamping(damping);
	}

	void RBPhysicsComponent::Update()
	{
		Vector2 position = B2VEC2_TO_VECTOR2(body_->GetPosition());
		owner_->transform_.position = PhysicsSystem::WorldToScreen(position);
		owner_->transform_.rotation = body_->GetAngle();
	}

	void RBPhysicsComponent::ApplyForce(const Vector2& force)
	{
		body_->ApplyForceToCenter(VECTOR2_TO_B2VEC2(force), true);
	}

	bool RBPhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool RBPhysicsComponent::Read(const rapidjson::Value& value)
	{
		PhysicsComponent::Read(value);

		READ_DATA(value, data.gravity_scale);
		READ_DATA(value, data.constrain_angle);
		READ_DATA(value, data.is_dynamic);

		return true;
	}

	void RBPhysicsComponent::GravitySwitch()
	{
		float grav = body_->GetGravityScale();
		grav = grav * -1;
		body_->SetGravityScale(grav);
	}
}