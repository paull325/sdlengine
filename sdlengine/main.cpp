#define SDL_MAIN_HANDLED

#include "engine/stdinclude.h"

#include "engine/window.h"
#include "engine/keyListener.h"
#include "engine/gameObject.h"
#include "engine/player.h"
#include "engine/globalScene.h"
#include "engine/scene.h"

void startGame(simpleEngine::globalScene* global) /* add game components here */
{
    {
        simpleEngine::scene scene1("scene1");

        simpleEngine::player p(global);
        p.loadSprite("image.png");
        p.geometry()->xSize(10);
        p.geometry()->ySize(20);

        simpleEngine::gameObject g(global, "ABCDERF");
        g.loadSprite("image.png");
        g.geometry()->xSize(300);
        g.geometry()->ySize(100);
        g.geometry()->move(100, 100);

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
-collision
-graphics scale factor
-deltatime
-movement via acceleration
*/