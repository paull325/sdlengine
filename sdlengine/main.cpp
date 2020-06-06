#define SDL_MAIN_HANDLED

#include "engine/stdinclude.h"

#include "engine/window.h"
#include "engine/gameObject.h"
#include "engine/globalScene.h"
#include "engine/input.h"

simpleEngine::globalScene global;
simpleEngine::window globalWindow;

namespace gameObjectFunction /*gameObject load and update functions here*/
{
    
    void load_testEnt()
    {

    }

    void update_testEnt()
    {
        if (simpleEngine::checkKeyDown(SDL_SCANCODE_ESCAPE)) {
            global.end();
        }
        if (simpleEngine::checkKeyDown(SDL_SCANCODE_W))
        {
            global.getSceneById(0)->getEntityById(0)->move(0, -10);
            global.getSceneById(0)->getEntityById(1)->move(0, 10);
        }
        else if (simpleEngine::checkKeyDown(SDL_SCANCODE_S))
        {
            global.getSceneById(0)->getEntityById(0)->move(0, 10);
            global.getSceneById(0)->getEntityById(1)->move(0, -10);
        }
        if (simpleEngine::checkKeyDown(SDL_SCANCODE_A))
        {
            global.getSceneById(0)->getEntityById(0)->move(-10, 0);
            global.getSceneById(0)->getEntityById(1)->move(10, 0);
        }
        else if (simpleEngine::checkKeyDown(SDL_SCANCODE_D))
        {
            global.getSceneById(0)->getEntityById(0)->move(10, 0);
            global.getSceneById(0)->getEntityById(1)->move(-10, 0);
        }
    }
}

namespace sceneFunction /*scene load and update functions here*/
{
    void load_scene1()
    {
        simpleEngine::entity testEnt("ENTITY", &gameObjectFunction::load_testEnt, &gameObjectFunction::update_testEnt);
        testEnt.loadSprite("image.png");
        global.getSceneById(0)->addEntity(testEnt);

        simpleEngine::entity testEnt2("ENTITY2");
        testEnt2.loadSprite("image.png");
        testEnt2.move(790, 590);
        global.getSceneById(0)->addEntity(testEnt2);
    }

    void update_scene1()
    {
       
    }

}

void startGame()  /*add scenes here*/
{
    {
        simpleEngine::scene scene1("scene1", &sceneFunction::load_scene1, &sceneFunction::update_scene1);
        global.addScene(scene1);
    }
    global.start();
    global.unloadSceneByName("scene1");

    SDL_Delay(1000);

    {
        simpleEngine::scene scene2("scene2", &sceneFunction::load_scene1, &sceneFunction::update_scene1);
        global.addScene(scene2);
    }
    global.start();
    global.unloadSceneByName("scene2");
}

int main(int argc, char* argv[])
{
    SDL_SetMainReady();

    if (!globalWindow.create("Title", 800, 600))
    {
        std::cout << "Error while creating window" << std::endl;
        return 1;
    }

    startGame();

    return 0;
}