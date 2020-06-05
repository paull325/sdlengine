#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

namespace simpleEngine
{
	class window
	{
	public:
		window();
		~window();

		bool create(const std::string& windowTitle, const int windowWidth, const int windowHeight);
		bool renderImage(const std::string& imagePath, const int xPosition, const int yPosition);

	private:
		SDL_Window* m_window;
		SDL_Renderer* renderer;

		bool init();
	};

	class gameObject
	{
	public:
		gameObject(const std::string& gameObjectName);
		gameObject(const std::string& gameObjectName, void(*loadFunction)(), void(*updateFunction)());
		~gameObject();

		std::string gameObjectName();
		void setGameObjectName(const std::string& gameObjectName);

		void onLoad();
		void setUpdateFunction(void(*updateFunction)());
		void updateGameObject();

	private:
		std::string m_gameObjectName;

		void(*m_updateFunction)();
		void(*m_loadFunction)();
	};

	class scene
	{
	public:
		scene();
		scene(const std::string& sceneName, void(*loadFunction)(), void(*updateFunction)());
		~scene();

		std::string sceneName();
		void setSceneName(const std::string& gameObjectName);

		void end();
		void onLoad();
		void update();

		bool addGameObject(gameObject obj);
		gameObject* getGameObjectByName(const std::string& gameObjectName);
		gameObject* getGameObjectById(const int id);

		size_t getGameObjectListSize();

	protected:
		bool m_active;
		std::vector<gameObject> m_gameObjectList;

		virtual bool init();

	private:
		std::string m_sceneName;

		void(*m_updateFunction)();
		void(*m_loadFunction)();
	};

	class globalScene : public scene
	{
	public:
		globalScene();
		~globalScene();

		bool addScene(scene sc);
		bool unloadSceneByName(const std::string sceneName);
		bool unloadSceneById(const int id);

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(const int id);

		bool start();

	private:
		std::vector<scene> m_sceneList;
		unsigned int m_sceneID;
	};
}

extern simpleEngine::globalScene global;
extern simpleEngine::window window;