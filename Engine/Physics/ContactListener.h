#pragma once
#include "Physics/PhysicsSystem.h"
#include "C:\Users\loren\OneDrive\Desktop\School Files\GAT150\ThirdParty\box2d\include\box2d\b2_body.h"
#include "C:\Users\loren\OneDrive\Desktop\School Files\GAT150\ThirdParty\box2d\include\box2d\b2_contact.h"

namespace Engine
{
	class ContactListener : public b2ContactListener
	{
	public:

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}