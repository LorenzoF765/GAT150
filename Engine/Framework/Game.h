#pragma once
#include <memory>

namespace Engine
{
	class Renderer;
	class Scene;

	class Game
	{

	public:

		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int GetScore() { return score_; }
		void AddPoints(int points) { score_ += points; }

	protected:

		std::unique_ptr<Scene> scene_;
		int score_ = 000000;
	};
}
