#pragma once
#include "stdinclude.h"
#include "scene.h"

namespace simpleEngine
{
	class globalScene : public scene
	{
	public:
		globalScene();
		~globalScene();

		void end();

		bool addScene(scene& sc);
		bool unloadSceneByName(const std::string sceneName);
		bool unloadSceneById(int id);

		scene* getSceneByName(const std::string sceneName);
		scene* getSceneById(int id);

		bool start();

	private:
		std::vector<scene> m_sceneList;
		bool m_active;
		int m_sceneID;
	};
}

extern simpleEngine::globalScene global;