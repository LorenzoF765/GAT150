#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace Engine
{
	class RBPhysicsComponent : public PhysicsComponent
	{
	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		CLASS_DECLARATION(RBPhysicsComponent)

		void Initialize() override;
		void Update() override;

		virtual void ApplyForce(const Vector2& force) override;
		
		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		void GravitySwitch();

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* body_ = nullptr;

	};
}
