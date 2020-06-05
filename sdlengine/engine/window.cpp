#include <engine.h>

namespace simpleEngine
{
	window::window()
	{
        if(!init())
            std::cout << "Initialization failed." << std::endl;
        else
            std::cout << "Window created." << std::endl;
	}

	window::~window()
	{
        // Close and destroy the window
        SDL_DestroyWindow(m_window);

        // Clean up
        SDL_Quit();

        std::cout << "Window closed." << std::endl;
	}

    bool window::init()
    {
        m_window = NULL;
        return true;
    }

	bool window::create(const std::string windowTitle, const int windowWidth, const int windowHeight)
	{
        SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

        // Create an application window with the following settings:
        m_window = SDL_CreateWindow(
            windowTitle.c_str(),                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            windowWidth,                               // width, in pixels
            windowHeight,                               // height, in pixels
            SDL_WINDOW_OPENGL                  // flags - see below
        );

        // Check that the window was successfully created
        if (m_window == NULL) {
            //std::cout << "Could not create window: " << SDL_GetError() << "\n";
            return false;
        }

        return true;
	}
}