#include "Font.h"
#include <SDL_TTF.h>

namespace Solas
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Load(filename, fontSize);
	}

	Font::~Font()
	{
		if (ttfFont_ != NULL)
		{
			TTF_CloseFont(ttfFont_);
		}
	}

	void Font::Load(const std::string& filename, int fontsize)
	{
		ttfFont_ = TTF_OpenFont(filename.c_str(), fontsize);
	}
}