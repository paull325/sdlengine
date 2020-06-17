#pragma once
#include "stdinclude.h"
#include "scene.h"

namespace simpleEngine
{
	class globalScene : public scene
	{
	public:
		globalScene(window* win, keyListener* key) { m_window = win; m_key = key; m_active = true; };
		~globalScene() {};

		bool addScene(scene& sc);
		bool unloadSceneByName(const std::string sceneName);
		bool unloadSceneById(int id);

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(int id);

		window* getWindow() { return m_window; };
		keyListener* key() { return m_key; };

		bool start();

	private:
		keyListener* m_key;
		window* m_window;
		std::vector<scene> m_sceneList;
	};
}