#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Factory.h"

namespace Engine
{
	Actor::Actor(const Actor& other)
	{
		name_ = other.name_;
		tag_ = other.tag_;
		transform_ = other.transform_;
		scene_ = other.scene_;

		for (auto& component : other.components_)
		{
			auto clone = std::unique_ptr<Component>((Component*)component->Clone().release());
			AddComponent(std::move(clone));
		}
	}

	void Engine::Actor::Draw(Renderer& renderer)
	{
		if (!active_)
		{
			return;
		}
		for (auto& component : components_)
		{
			//component->Update();
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent)
			{
				renderComponent->Draw(renderer);
			}
		}

		for (auto& child : children_)
		{
			child->Draw(renderer);
		}
	}
	void Actor::AddChild(std::unique_ptr<Actor> child)
	{
		child->parent_ = this;
		child->scene_ = this->scene_;
		children_.push_back(std::move(child));
	}
	void Actor::AddComponent(std::unique_ptr<Component> component)
	{
		// Sets the owner of the component to THIS Actor instance
		component->owner_ = this;

		// Adds the component to the list of components in this Actor 
		components_.push_back(std::move(component));
	}
	void Actor::Initialize()
	{
		for (auto& component : components_) { component->Initialize(); }
		for (auto& child : children_) { child->Initialize(); }
	}
	void Engine::Actor::Update()
	{
		if (!active_)
		{
			return;
		}
		for (auto& component : components_)
		{
			component->Update();
		}
		for (auto& child : children_)
		{
			child->Update();
		}
		if (parent_ != nullptr)
		{
			transform_.Update(parent_->transform_.matrix);
		}
		else
		{
			transform_.Update();
		}
	}

	bool Actor::Write(const rapidjson::Value& value) const { return true; }

	bool Actor::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, tag_);
		READ_DATA(value, name_);
		READ_DATA(value, active_);

		if (value.HasMember("transform")) transform_.Read(value["transform"]);
		if (!(value.HasMember("transform")) || !value["transform"].IsArray())
		{
			for (auto& componentValue : value["components"].GetArray())
			{
				std::string type;
				READ_DATA(componentValue, type);

				auto component = Factory::Instance().Create<Component>(type);
				if (component)
				{
					component->Read(componentValue);
					AddComponent(std::move(component));
				}
			}
		}

		return true;
	}
}
