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

		bool create(const std::string windowTitle, const int windowWidth, const int windowHeight);

	private:
		SDL_Window* m_window;

		bool init();
	};

	class gameObject
	{
	public:
		gameObject(const std::string gameObjectName);
		gameObject(const std::string gameObjectName, void(*loadFunction)(), void(*updateFunction)());
		~gameObject();

		std::string gameObjectName();
		void setGameObjectName(const std::string gameObjectName);

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
		scene(std::string sceneName, void(*loadFunction)(), void(*updateFunction)());
		~scene();

		std::string sceneName();
		void setSceneName(const std::string gameObjectName);

		void end();
		void onLoad();
		void update();

		bool addGameObject(gameObject obj);
		gameObject* getGameObjectByName(const std::string gameObjectName);
		gameObject* getGameObjectById(unsigned int id);

		unsigned int getGameObjectListSize();

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
		bool unloadSceneById(unsigned int id);

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(unsigned int id);

		bool start();

	private:
		std::vector<scene> m_sceneList;
		unsigned int m_sceneID;
	};


	/*/////////////////////LEGACY////////////////////////
	class game
	{
	public:
		game();
		~game();

		bool start();
		void end();

		bool addGameObject(gameObject obj);
		gameObject* getGameObject(const std::string gameObjectName);
	
	protected:
		bool m_active;
		std::vector<gameObject> m_gameObjectList;

		virtual bool init();
	};

	class scene : public game
	{
	public:
		scene(std::string sceneName, void(*loadFunction)(), void(*updateFunction)());
		~scene();

		void onLoad();
		void update();

	private:
		std::string m_sceneName;
		std::vector<game> m_sceneList;

		void(*m_updateFunction)();
		void(*m_loadFunction)();
	};
	///////////////////////////////////////////////////////*/
}

extern simpleEngine::globalScene global;