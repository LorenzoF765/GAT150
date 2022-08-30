#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include "Math/MathUtils.h"

#include <iostream>
#include <sstream>

namespace Solas
{
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale) {

		for (int i = 0; i < points_.size() - 1; i++)
		{
			Vector2 p1 = Vector2::Rotate((points_[i] * scale), angle) + position;
			Vector2 p2 = Vector2::Rotate((points_[i + 1] * scale), angle) + position;
			renderer.DrawLine(p1, p2, color_);
		}
	}

	void Model::Draw(Renderer& renderer, const Transform& transform) {
		if (points_.size() == 0) {
			return;
		}

		Matrix3x3 mx = transform.matrix;

		for (int i = 0; i < points_.size() - 1; i++)
		{
			/*Vector2 p1 = Vector2::Rotate((points_[i] * transform.scale), Math::DegToRad(transform.rotation)) + transform.position;
			Vector2 p2 = Vector2::Rotate((points_[i + 1] * transform.scale), Math::DegToRad(transform.rotation)) + transform.position;*/
			Vector2 p1 = mx * points_[i];
			Vector2 p2 = mx * points_[i + 1];
			renderer.DrawLine(p1, p2, color_);
		}
	}

	bool Model::Load(const std::string& filename) {
		std::string buffer;
		Solas::readFile(filename, buffer);
		if (!Solas::readFile(filename, buffer)) {
			LOG("Error could not load model %s", filename.c_str());
			return false;
		}

		std::istringstream stream(buffer);
		stream >> color_;

		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			points_.push_back(point);
		}

		return true;
	}

	float Model::CalculateRadius()
	{
		float radius = 0;

		for (auto& point : points_) {
			if (point.Length() > radius) {
				radius = point.Length();
			}
		}

		return radius;
	}

	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();
		std::cout << m_radius << std::endl;
	}

	bool Model::Create(const std::string& filename, void* data) {
		if (!Load(filename)) {
			LOG("Error could not create model.");
			return false;
		}

		return true;
	}
}