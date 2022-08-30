#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Solas {
	//Forward Declaration
	class Actor;
	class Renderer;
	class Game;

	class Scene {
	public:
		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

		Game* GetGame() {
			//fill with code
		}

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
	};

	template<typename T>
	inline T* Scene::GetActor() {
		for (auto& actor : m_actors) {
			T* result = dynamic_cast<T*>(actor.get());
			if (result) {
				return result;
			}
		}

		return nullptr;
	}
}