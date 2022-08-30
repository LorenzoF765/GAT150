#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Serialization/Json.h"
#include <vector>

namespace Engine
{
	class Scene;
	class Component;
	class Renderer;

	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Actor& other);
		Actor(const Transform& transform) : transform_{ transform } {}

		CLASS_DECLARATION(Actor)

			virtual void Initialize() override;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void AddChild(std::unique_ptr<Actor> child);
		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}

		//Getters and Setters
		float GetRadius() { return 0; } // model_.GetRadius()* std::max(transform_.scale.x, transform_.scale.y);

		std::string& GetTag() { return tag_; }
		void SetTag(std::string tag) { tag_ = tag; }

		std::string& GetName() { return name_; }
		void SetName(const std::string name) { this->name_ = name; }

		bool GetDestroy() { return destroy_; }
		void SetDestroy(bool destroy) { destroy_ = destroy; }

		bool GetActive() { return active_; }
		void SetActive(bool& active) { active_ = active; };

		Scene* GetScene() { return scene_; }

		friend class Scene;

		// State

		Transform transform_;

	protected:

		std::string tag_;
		std::string name_;
		bool active_ = true;
		bool destroy_ = false;

		// Physics
		Vector2 velocity_;
		float damping_ = 1;

		// Object
		Scene* scene_ = nullptr;
		Actor* parent_ = nullptr;

		std::vector<std::unique_ptr<Component>> components_;
		std::vector < std::unique_ptr<Actor>> children_;

	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : components_)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}
}