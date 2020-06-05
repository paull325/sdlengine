#define SDL_MAIN_HANDLED

#include <engine.h>

simpleEngine::globalScene global;

Uint8* keyboard;

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

    void update_scene1()
    {
        
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

    simpleEngine::window window;

    if (!window.create("Title", 800, 600))
    {
        std::cout << "Error while creating window" << std::endl;
        return 1;
    }

    startGame();

    return 0;
}