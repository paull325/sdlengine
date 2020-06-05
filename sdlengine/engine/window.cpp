#include <engine.h>

namespace simpleEngine
{
	window::window()
	{
        if (!init())
        {
            std::cout << "Initialization failed." << std::endl;
        }
        else
        {
            std::cout << "Window created." << std::endl;
        }
    }

	window::~window()
	{
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(renderer);

        IMG_Quit();
        SDL_Quit();

        std::cout << "Window closed." << std::endl;
	}

    bool window::init()
    {
        m_window = NULL;
        return true;
    }

	bool window::create(const std::string& windowTitle, const int windowWidth, const int windowHeight)
	{
        SDL_Init(SDL_INIT_VIDEO);

        m_window = SDL_CreateWindow(
            windowTitle.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            windowWidth,
            windowHeight,
            SDL_WINDOW_OPENGL
        );

        if (m_window == NULL)
        {
            return false;
        }

        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            return false;
        }
        renderer = SDL_CreateRenderer(m_window, -1, 0);

        return true;
	}

    bool window::renderImage(const std::string& imagePath, const int xPosition, const int yPosition)
    {
        SDL_Surface* image = IMG_Load(imagePath.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_Rect rect = { xPosition, yPosition, 10, 10 };
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(image);

        return true;
    }
}