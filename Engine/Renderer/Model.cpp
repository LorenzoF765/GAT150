#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include "Math/MathUtils.h"

#include <cstdarg>
#include <iostream>
#include <sstream>

namespace Engine
{
	//bool Model::Create(const std::string filename, ...)
	//{
	//	if (!Load(filename))
	//	{
	//		LOG("Error: Could Not Create Model.");
	//		return false;
	//	}
	//	return true;
	//}

	bool Model::Create(const std::string filename, ...)
	{
		va_list args;

		va_start(args, filename);

		Renderer& renderer = va_arg(args, Renderer);

		va_end(args);

		return Create(filename, renderer);
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
	{

		for (int i = 0; i < points_.size() - 1; i++)
		{
			Engine::Vector2 p1 = Vector2::Rotate((points_[i] * scale), angle) + position;
			Engine::Vector2 p2 = Vector2::Rotate((points_[i + 1] * scale), angle) + position;
			renderer.DrawLine(p1, p2, color_);
		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		if (points_.size() == 0)
		{
			return;
		}

		Matrix3x3 mx;

		for (int i = 0; i < points_.size() - 1; i++)
		{
			Vector2 p1 = mx * points_[i];
			Vector2 p2 = mx * points_[i + 1];
			renderer.DrawLine(p1, p2, color_);
		}
	}

	bool Model::Load(const std::string& filename)
	{
		std::string buffer;
		Engine::ReadFile(filename, buffer);

		if (!ReadFile(filename, buffer))
		{
			LOG("Error: Could not load model %s", filename.c_str());
			return false;
		}

		// Read Color
		std::istringstream stream(buffer);
		stream >> color_;

		// Read Number of Points
		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		//// Read Model Points
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

		// Find Largest Length
		for (auto& point : points_)
		{
			if (point.Length() > radius) radius = point.Length();
		}

		return radius;
	}
}