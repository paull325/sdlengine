#define SDL_MAIN_HANDLED

#include "engine/stdinclude.h"

#include "engine/window.h"
#include "engine/gameObject.h"
#include "engine/globalScene.h"

simpleEngine::globalScene global;
simpleEngine::window window;

namespace gameObjectFunction /*gameObject load and update functions here*/
{
    
    void load_testObj()
    {

    }

    void update_testObj()
    {
        SDL_PumpEvents();
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_ESCAPE]) {
            global.end();
        }
    }
}

namespace sceneFunction /*scene load and update functions here*/
{
    void load_scene1()
    {
        simpleEngine::gameObject testObj("TESTOBJ", &gameObjectFunction::load_testObj, &gameObjectFunction::update_testObj);
        global.getSceneById(0)->addGameObject(testObj);
    }

    int i = 0;

    void update_scene1()
    {
        window.renderImage("image.png", i, 100);
        i++;
    }

}

void startGame()
{
    {
        simpleEngine::scene scene1("scene1", &sceneFunction::load_scene1, &sceneFunction::update_scene1);
        global.addScene(scene1);
    }
    global.start();
    global.unloadSceneByName("scene1");
}

int main(int argc, char* argv[])
{
    SDL_SetMainReady();

    if (!window.create("Title", 800, 600))
    {
        std::cout << "Error while creating window" << std::endl;
        return 1;
    }

    startGame();

    return 0;
}