#pragma once
#include <string>

namespace Solas
{
	class Resource
	{
	public:
		virtual bool Create(const std::string name, ...) = 0;
	};
}