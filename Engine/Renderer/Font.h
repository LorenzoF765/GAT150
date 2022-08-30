#pragma once
#include <string>

struct _TTF_Font;

namespace Solas
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontsize);

		friend class Text;

	private:

		_TTF_Font* ttfFont_ = nullptr;

	};
}