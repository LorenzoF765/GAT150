#include "Text.h"
#include "../Math/Color.h"
#include "Renderer.h"
#include "../Renderer/Font.h"
#include <SDL_ttf.h> 

Engine::Text::~Text()
{
	if (texture_ != NULL)
	{
		SDL_DestroyTexture(texture_);
	}
}

void Engine::Text::Create(Renderer& renderer, const std::string text, const Color& color)
{
	SDL_Color c{ color.r, color.g, color.b, color.a };
	SDL_Surface* surface = TTF_RenderText_Solid(font_->ttfFont_, text.c_str(), c);

	texture_ = SDL_CreateTextureFromSurface(renderer.renderer_, surface);
	SDL_FreeSurface(surface);
}

void Engine::Text::Draw(Renderer& renderer, const Vector2& position)
{
	int width, height;
	SDL_QueryTexture(texture_, nullptr, nullptr, &width, &height);

	SDL_Rect rect{ (int)position.x, (int)position.y, width, height };

	SDL_RenderCopy(renderer.renderer_, texture_, NULL, &rect);

}
