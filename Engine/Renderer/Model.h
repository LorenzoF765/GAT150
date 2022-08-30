#pragma once
#include "Renderer.h"
#include "Resource/Resource.h"
#include <vector>
#include <string>


namespace Engine
{
	class Model : public Resource
	{

	public:

		Model() = default;
		Model(const std::vector<Vector2>& points, const Color& color) : points_{ points }, color_{ color } {}
		Model(const std::string& filename)
		{
			Load(filename);
			radius_ = CalculateRadius();
		}

		bool Create(const std::string filename, ...)override;

		void Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale = Vector2{ 1,1 });
		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& filename);

		float GetRadius() { return radius_; }
		float CalculateRadius();

	private:

		Color color_{ 0, 0, 0, 0 };
		std::vector<Vector2> points_;
		float radius_ = 0;

	};
}
