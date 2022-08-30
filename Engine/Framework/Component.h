#pragma once
#include "GameObject.h"

namespace Solas {
	class Actor;

	class Component : public GameObject {
	public:
		Component() = default;
		~Component() = default;

		friend class Actor;
	protected:
		Actor* m_owner = 0;
	};
}