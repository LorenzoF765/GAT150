#pragma once
#include "C:\Users\loren\OneDrive\Desktop\Solas-Final\ThirdParty\box2d\include\box2d\box2d.h"

namespace Solas
{
	class ContactListener : public b2ContactListener
	{
	public:
		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}