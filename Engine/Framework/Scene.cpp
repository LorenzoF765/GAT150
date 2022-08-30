#include "Scene.h"
#include "Factory.h"
#include "Core/Logger.h"
#include <iostream>

namespace Engine
{
	void Scene::Initialize()
	{
		for (auto& actor : actors_) { actor->Initialize(); }
	}
	void Scene::RemoveAll()
	{
		actors_.clear();
	}
	void Scene::Update()
	{
		auto iter = actors_.begin();
		while (iter != actors_.end())
		{
			(*iter)->Update();
			if ((*iter)->destroy_)
			{
				iter = actors_.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : actors_)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->scene_ = this;
		actors_.push_back(std::move(actor));
	}
	bool Scene::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool Scene::Read(const rapidjson::Value& value)
	{
		if (!value.HasMember("actors") || !value["actors"].IsArray())
		{
			LOG("Error reading file, neither an Actor nor Array");
			return false;
		}

		//read actors
		for (auto& actorValue : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(actorValue, type);

			auto actor = Factory::Instance().Create<Actor>(type);
			if (actor)
			{
				actor->Read(actorValue);

				bool prefab = false;
				READ_DATA(actorValue, prefab);

				if (prefab)
				{
					std::string name = actor->GetName();
					Factory::Instance().RegisterPrefab(name, std::move(actor));
				}
				else
				{
					Add(std::move(actor));
				}
			}
		}

		return true;
	}
}