#pragma once
#include "Vector2.h"
#include <Math/Mat2_2.h>
#include "MathUtils.h"
#include "Serialization/Serialization.h"
#include <Math/Mat3_3.h>

namespace Engine
{
	struct Transform : public ISerializable
	{
		Vector2 position;
		float rotation;
		Vector2 scale{ 1, 1 };

		virtual bool Write(const rapidjson::Value& value) const override { return true; }
		virtual bool Read(const rapidjson::Value& value) override
		{
			READ_DATA(value, position);
			READ_DATA(value, rotation);
			READ_DATA(value, scale);

			return true;
		}

		Matrix3x3 matrix;
		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };

		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };
			matrix = parent * matrix;
		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxScale * mxRotation * mxTranslation };
		}

		operator Matrix2x2 () const
		{
			Matrix2x2 mxScale = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRotation(rotation);

			return { mxScale * mxRotation };
		}
	};
}