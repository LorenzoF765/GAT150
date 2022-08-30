#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
#include <functional>

namespace Engine
{
	class CollisionComponent : public Component, public ICollision
	{
	public:

		using functionpr = std::function<void(Actor*)>;

		CLASS_DECLARATION(CollisionComponent)

		virtual void Initialize() override;
		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override ;
		virtual bool Read(const rapidjson::Value& value) override ;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		void SetCollisionEnter(functionpr function) { enterFunction_ = function; }
		void SetCollisionExit(functionpr function) { exitFunction_ = function; }

	private:

		PhysicsSystem::CollisionData data;
		functionpr enterFunction_;
		functionpr exitFunction_;

	};
}