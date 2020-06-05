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
		bool renderImage(const std::string& imagePath, int xPosition, int yPosition);

	private:
		SDL_Window* m_window;
		SDL_Renderer* renderer;

		bool init();
	};
}

extern simpleEngine::window window;