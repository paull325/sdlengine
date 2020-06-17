#include "stdinclude.h"
#include "entity.h"

namespace simpleEngine
{
    void keyListener::update()
    {
        SDL_PumpEvents(); //or SDL_PollEvent(&e); ?
    }

    bool keyListener::checkKeyDown(SDL_Scancode code)
    {
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

