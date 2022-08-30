#include "Font.h"
#include "Core/Logger.h"
#include "Math/Color.h"
#include <SDL_TTF.h>

namespace Engine
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

	bool Font::Create(const std::string& filename, int& fontsize)
	{
		if (!Load(filename, fontsize))
		{
			return false;
		}
		return true;
	}

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(ttfFont_, text.c_str(), c);

		if (!surface)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}

	bool Font::Create(std::string filename, ...)
	{
		// va_list - type to hold information about variable arguments 
		va_list args;

		// va_start - enables access to variadic function arguments 
		va_start(args, filename);

		// va_arg - accesses the next variadic function arguments 
		int& fontSize = va_arg(args, int);

		// va_end - ends traversal of the variadic function arguments 
		va_end(args);

		// create texture (returns true/false if successful) 
		return Create(filename, fontSize);
	}


	bool Font::Load(const std::string& filename, int fontsize)
	{
		ttfFont_ = TTF_OpenFont(filename.c_str(), fontsize);

		if (ttfFont_ == nullptr)
		{
			return false;
		}

		return true;
	}
}