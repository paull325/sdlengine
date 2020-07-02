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

        simpleEngine::gameObject g(global, "Background_obj");
        g.loadSprite("image.png");
        g.geometry()->xSize(800);
        g.geometry()->ySize(600);

        simpleEngine::gameObject text(global, "text");
        text.loadSprite("anno.png");
        text.geometry()->set(700, 50, 50, 50);

        simpleEngine::gameObject text2(global, "text2");
        text2.loadSprite("anno.png");
        text2.geometry()->set(700, 120, 50, 50);

        simpleEngine::gameObject letter(global, "letter");
        letter.tile(9, 5);
        letter.loadSprite("anno.png");
        letter.geometry()->set(640, 50, 50, 50);

        simpleEngine::gameObject letter2(global, "letter2");
        letter2.tile(8, 5);
        letter2.loadSprite("anno.png");
        letter2.geometry()->set(640, 120, 50, 50);

        simpleEngine::player p(global);
        p.layer(1);
        p.loadSprite("sprite.png");
        p.maxSpeed(10.0);
        p.geometry()->xAcc(1);
        p.geometry()->yAcc(1);
        p.geometry()->xSize(60);
        p.geometry()->ySize(60);

        scene1.addGameObject<simpleEngine::gameObject>(g);
        scene1.addGameObject<simpleEngine::gameObject>(text);
        scene1.addGameObject<simpleEngine::gameObject>(text2);
        scene1.addGameObject<simpleEngine::gameObject>(letter);
        scene1.addGameObject<simpleEngine::gameObject>(letter2);
        scene1.addGameObject<simpleEngine::player>(p);

        global->addScene(scene1);
    }
    global->start();
    global->unloadSceneByName("scene1");
}

int main(int argc, char* argv[])
{
    SDL_SetMainReady();

    simpleEngine::window g_window;

    if (!g_window.create("Wizard Game", 800, 600))
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
        WIP:
-movement via acceleration (p_movement.cpp) (bugged, accel not correct)
-collision (scene.cpp)

        Todo:
-graphics scale factor
-deltatime
*/