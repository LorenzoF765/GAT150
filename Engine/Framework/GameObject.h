#pragma once
#include "Math/Transform.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)

namespace Solas
{
	class GameObject
	{
	public:

		GameObject() = default;

		virtual void Update() = 0;
	};
}