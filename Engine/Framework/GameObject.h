#pragma once
#include "../Math/Transform.h"
#include "Serialization/Serialization.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);
#define CLASS_DECLARATION(class) \
	std::unique_ptr<GameObject> Clone() override { return std::make_unique<class>(*this); }
namespace Engine
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}