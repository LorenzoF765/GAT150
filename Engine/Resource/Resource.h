#pragma once
#include <string>

// Resource Class
namespace Engine
{
	class Resource
	{
	public:
		//virtual bool Create(const std::string& name, void* data = nullptr) = 0;
		virtual bool Create(const std::string filename, ...) = 0;
	};
}