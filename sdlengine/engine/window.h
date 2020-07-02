#pragma once
#include "stdinclude.h"

namespace simpleEngine
{
	class window
	{
	public:
		window();
		~window();

		bool create(const std::string& windowTitle, int windowWidth, int windowHeight);
		bool renderImage(SDL_Surface* image, geometryPtr g, unsigned char xTile, unsigned char yTile, bool look);
		void render();
		void reset();

	private:
		SDL_Window* m_window;
		SDL_Renderer* renderer;
	};
}