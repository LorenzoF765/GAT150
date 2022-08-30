#include "Texture.h"
#include "Renderer/Renderer.h"
#include "Core/Logger.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Solas {
	Texture::~Texture() {
		if (m_texture != NULL) {
			SDL_DestroyTexture(m_texture);
		}
	}

	bool Texture::Create(const std::string& filename, void* data) {
		//(Renderer*)(data);
		Renderer* renderer = static_cast<Renderer*>(data);
		return Create(*renderer, filename);
	}

	bool Texture::Create(Renderer& renderer, const std::string& filename) {
		SDL_Surface* surface = IMG_Load(filename.c_str());
		if (surface == nullptr) {
			LOG(SDL_GetError());
			return false;
		}

		m_texture = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface);
		if (m_texture == nullptr) {
			LOG(SDL_GetError());
			SDL_FreeSurface(surface);
			return false;
		}

		//SDL_FreeSurface(surface);

		return true;
	}


	Vector2 Texture::GetSize() const {
		SDL_Point point;
		SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);
		return Vector2{ point.x, point.y };
	}
}