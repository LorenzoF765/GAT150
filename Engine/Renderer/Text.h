#pragma once
#include <string>

struct SDL_Texture;

namespace Engine
{
	class Font;
	class Renderer;
	struct Vector2;
	struct Color;

	class Text
	{
	public:
		Text() = default;
		Text(Font* font) : font_{ font } {}
		~Text();

		void Create(Renderer& renderer, const std::string text, const Color& color);
		void Draw(Renderer& renderer, const Vector2& position);

	private:
		Font* font_ = nullptr;
		SDL_Texture* texture_ = nullptr;
	};
}
