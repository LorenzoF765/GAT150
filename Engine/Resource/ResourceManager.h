#pragma once
#include "Resource.h"
#include <map>
#include <string>
#include <memory>

namespace Solas {
	class ResourceManager {
	public:
		ResourceManager() = default;

		void Initialize();
		void Shutdown();

		template <typename T>
		std::shared_ptr<T> Get(const std::string& name, void* data = nullptr);
	private:
		std::map<std::string, std::shared_ptr<Resource>> m_resources;
	};

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::Get(const std::string& name, void* data)
	{
		if (m_resources.find(name) != m_resources.end()) {
			return std::dynamic_pointer_cast<T>(m_resources[name]);
		}else{
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(name, data);
			m_resources[name] = resource;

			return resource;
		}

		return std::shared_ptr<T>();
	}
}