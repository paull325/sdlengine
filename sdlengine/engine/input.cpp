#include "stdinclude.h"
#include "input.h"

namespace simpleEngine
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    //SDL_Event e;

    bool checkKeyDown(SDL_Scancode code)
    {
        SDL_PumpEvents();

        //SDL_PollEvent(&e);
        //std::cout << e.type << std::endl;

        if (keystate[code])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

