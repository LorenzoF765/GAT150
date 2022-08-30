#pragma once
#include <cstdint>
#include <iostream>

namespace Engine
{
	struct Color
	{
		uint8_t r, g, b, a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
		uint8_t  operator [] (size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return (&r)[index]; }

		friend class Text;
	};

	std::ostream& operator << (std::ostream& stream, const Color& color);
	std::istream& operator >> (std::istream& stream, Color& Color);
}
