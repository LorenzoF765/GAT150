#pragma once
#include "Resource.h"
#include <map>
#include <string>
#include <memory>

namespace Engine
{
    class ResourceManager
    {
    public:

        ResourceManager() = default;

        void Initialize();
        void ShutDown();

        template<typename T, typename ... TArgs>
        std::shared_ptr<T> Get(const std::string& name, TArgs ... args);

    private:

        std::map<std::string, std::shared_ptr<Resource>> resources_;

    };

    template<typename T, typename ... TArgs>
    inline std::shared_ptr<T> ResourceManager::Get(const std::string& name, TArgs ... args)
    {
        if (resources_.find(name) != resources_.end())
        {
            return std::dynamic_pointer_cast<T>(resources_[name]);
        }
        else
        {
            std::shared_ptr<T> resource = std::make_shared<T>();
            resource->Create(name, args...);
            resources_[name] = resource;

            return resource;
        }

        return std::shared_ptr<T>();
    }
}