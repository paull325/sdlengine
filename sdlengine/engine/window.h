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
		bool renderImage(SDL_Surface* image, int xPosition, int yPosition);

	private:
		SDL_Window* m_window;
		SDL_Renderer* renderer;
	};
}

extern simpleEngine::window globalWindow;