#pragma once
#include "stdinclude.h"
#include "scene.h"

namespace simpleEngine
{
	class globalScene
	{
	public:
		globalScene(window* win, keyListener* key) { m_frame = 0;  m_window = win; m_key = key; m_active = true; };
		~globalScene() {};

		bool addScene(scene& sc);
		bool unloadSceneByName(const std::string sceneName);
		bool unloadSceneById(int id) { m_sceneList.erase(m_sceneList.begin() + id); return true; };

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(int id) { return &m_sceneList.at(id); };

		int frame() { return m_frame; };

		window* getWindow() { return m_window; };
		keyListener* key() { return m_key; };

		bool start();

		bool loadSceneFile(const std::string fileName);

	private:
		bool m_active;
		int m_frame;
		keyListener* m_key;
		window* m_window;
		std::vector<scene> m_sceneList;
	};
}