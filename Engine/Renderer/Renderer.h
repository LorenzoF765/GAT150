#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include "Texture.h"

struct SDL_Renderer; // forward declaration
struct SDL_Window; // forward declaration

namespace Engine
{
	class Texture;
	struct Transform;
	struct Rect;

	class Renderer
	{
	public:

		Renderer() = default; // Constructor - Calls an instance of this class
		~Renderer() = default; // Destructor - Destroys an instance of this class

		void Initialize();
		void ShutDown();

		void CreateWindow(const char* title, int width, int height); // Assigns a title and a size to create a window which displays our work

		void BeginFrame();
		void EndFrame();

		void SetClearColor(Color color) { clearColor_ = color; } // Sets a background color

		void DrawLine(float x1, float y1, float x2, float y2); // Draws a line using floats
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color); // Draws a line using vectors and assigns a color

		void DrawPoint(float x, float y); // Draws a point using floats
		void DrawPoint(const Vector2& v, const Color& color);

		void Draw(std::shared_ptr<Texture> texture, const Vector2& position, const float& angle = 0, const Vector2& scale = Vector2{ 1, 1 }, const Vector2& registration = Vector2{ 0.5f, 0.5f });
		void Draw(std::shared_ptr<Texture> texture, const Transform& transform, const Vector2& registration = Vector2{ 0.5f, 0.5f });
		void Draw(std::shared_ptr<Texture> texture, const Rect& source, const Transform& transform, const Vector2& registration = Vector2{ 0.5f, 0.5f });

		int GetWidth_() { return width_; }
		int GetHeight_() { return height_; }
		SDL_Renderer* GetRenderer_() { return renderer_; }

		friend class Text;
		friend class Texture;

	private:
		int width_ = 0;
		int height_ = 0;

		Color clearColor_{ 0, 0, 0, 255 };

		SDL_Renderer* renderer_ = nullptr; // (title)_ shows that this is a member variable
		SDL_Window* window_ = nullptr;
	};
}
