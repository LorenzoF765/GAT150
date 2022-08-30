#pragma once
#include "..\Math\Vector2.h"
#include "Resource/Resource.h"
#include "../ThirdParty/SDL2-2.0.22/include/SDL_surface.h"
#include <string>

struct SDL_Texture;

namespace Engine
{
	class Renderer;

	class Texture : public Resource
	{
	public:

		Texture() = default;
		~Texture();

		bool Create(const std::string filename, ...) override;
		bool CreateFromSurface(SDL_Surface* surface, Renderer& renderer);
		bool Create(Renderer& renderer, const std::string& filename);
		Vector2 GetSize() const;
		SDL_Texture* texture_ = nullptr;

	private:


	};
}