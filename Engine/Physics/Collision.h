#pragma once

namespace Solas
{
	class Actor;

	class ICollision
	{
	public:
		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionExit(Actor* other) = 0;

	};
}