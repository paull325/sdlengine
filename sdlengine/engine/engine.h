#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

#include <SDL.h>
#include <SDL_image.h>

namespace simpleEngine
{
	class window
	{
	public:
		window();
		~window();

		bool create(const std::string& windowTitle, int windowWidth, int windowHeight);
		bool renderImage(const std::string& imagePath, int xPosition, int yPosition);

	private:
		SDL_Window* m_window;
		SDL_Renderer* renderer;

		bool init();
	};

	class gameObject
	{
	public:
		gameObject(const std::string& gameObjectName);
		gameObject(const std::string& gameObjectName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~gameObject();

		std::string gameObjectName();
		void setGameObjectName(const std::string& gameObjectName);

		void onLoad();
		void setUpdateFunction(std::function<void()> updateFunction);
		void updateGameObject();

	private:
		std::string m_gameObjectName;

		std::function<void()> m_updateFunction;
		std::function<void()> m_loadFunction;
	};

	class scene
	{
	public:
		scene();
		scene(const std::string& sceneName, std::function<void()> loadFunction, std::function<void()> updateFunction);
		~scene();

		std::string sceneName();
		void setSceneName(const std::string& gameObjectName);

		void end();
		void onLoad();
		void update();

		bool addGameObject(gameObject& obj);
		gameObject* getGameObjectByName(const std::string& gameObjectName);
		gameObject* getGameObjectById(int id);

		size_t getGameObjectListSize();

	protected:
		bool m_active;
		std::vector<gameObject> m_gameObjectList;

		virtual bool init();

	private:
		std::string m_sceneName;

		std::function<void()> m_updateFunction;
		std::function<void()> m_loadFunction;
	};

	class globalScene : public scene
	{
	public:
		globalScene();
		~globalScene();

		bool addScene(scene& sc);
		bool unloadSceneByName(const std::string sceneName);
		bool unloadSceneById(int id);

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(int id);

		bool start();

	private:
		std::vector<scene> m_sceneList;
		int m_sceneID;
	};
}

extern simpleEngine::globalScene global;
extern simpleEngine::window window;