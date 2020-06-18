#define SDL_MAIN_HANDLED

#include "engine/stdinclude.h"

#include "engine/window.h"
#include "engine/keyListener.h"
#include "engine/gameObject.h"
#include "engine/globalScene.h"

void startGame(simpleEngine::globalScene* global) /* add game components here */
{
    {
        simpleEngine::scene scene1("scene1");

        simpleEngine::player p(global);
        p.loadSprite("image.png");

        simpleEngine::gameObject g(global, "ABCDERF");
        g.loadSprite("image.png");

        scene1.addGameObject<simpleEngine::player>(p);
        scene1.addGameObject<simpleEngine::gameObject>(g);
        global->addScene(scene1);
    }
    global->start();
    global->unloadSceneByName("scene1");
}

int main(int argc, char* argv[])
{
    SDL_SetMainReady();

    simpleEngine::window g_window;

    if (!g_window.create("Title", 800, 600))
    {
        std::cout << "Error while creating window" << std::endl;
        return 1;
    }

    simpleEngine::keyListener key;

    simpleEngine::globalScene global(&g_window, &key);

    startGame(&global);

    return 0;
}

/*
        Todo:
-change x and y pos to single data type
-graphics scale factor
-deltatime
-movement via acceleration
*/