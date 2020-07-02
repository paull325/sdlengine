#include "stdinclude.h"
#include "window.h"
#include "geometry.h"

namespace simpleEngine
{
	window::window()
	{
        m_window = NULL;
        renderer = NULL;
        
        std::cout << "Window created." << std::endl;
    }

	window::~window()
	{
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(renderer);

        IMG_Quit();
        SDL_Quit();

        std::cout << "Window closed." << std::endl;
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
        renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        return true;
	}

    bool window::renderImage(SDL_Surface* image, geometryPtr g, unsigned char xTile, unsigned char yTile, bool look)
    {
        SDL_Surface* new_s = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_RGBA8888, 0);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, new_s);

        SDL_Rect rect = { g->x(), g->y(), g->xSize(), g->ySize() };
        SDL_Rect section_rect = { 16*xTile, 16*yTile, 16, 16 };
        if (!look)
        {
            SDL_RenderCopy(renderer, texture, &section_rect, &rect);
        }
        else
        {
            SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(renderer, texture, &section_rect, &rect, 0, nullptr, flip);
        }
        SDL_DestroyTexture(texture);

        return true;
    }


    void window::render()
    {
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    void window::reset()
    {
        SDL_Surface* s;
        s = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, s);
        SDL_Rect rect = { 0, 0, 800, 600 };
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        
        SDL_DestroyTexture(texture);
    }
}