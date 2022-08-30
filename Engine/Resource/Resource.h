#pragma once
#include <string>

//Resource base class
namespace Solas {
	class Resource {
	public:
		virtual bool Create(const std::string& name, void* data = nullptr) = 0;
	};
}