#include "stdinclude.h"
#include "globalScene.h"
#include "keyListener.h"
#include "window.h"

namespace simpleEngine
{
	bool globalScene::addScene(scene& sc)
	{
		m_sceneList.emplace_back(std::move(sc));
		return true;
	}

	bool globalScene::unloadSceneByName(const std::string sceneName)
	{
		for (int i = 0; i < m_sceneList.size(); i++)
		{
			if (m_sceneList[i].sceneName() == sceneName)
			{
				m_sceneList.erase(m_sceneList.begin() + i);
				break;
			}
		}
		return true;
	}

	bool globalScene::unloadSceneById(int id)
	{
		m_sceneList.erase(m_sceneList.begin() + id);
		return true;
	}


	scene* globalScene::getSceneByName(const std::string sceneName)
	{
		for (int i = 0; i < m_sceneList.size(); i++)
		{
			if (m_sceneList[i].sceneName() == sceneName)
			{
				return &m_sceneList[i];
			}
		}
		return nullptr;
	}

	scene* globalScene::getSceneById(int id)
	{
		return &m_sceneList.at(id);
	}

	bool globalScene::start()
	{
		int m_sceneID = 0;

		if (m_sceneList.size() == 0)
		{
			return false;
		}

		m_sceneList[m_sceneID].load();					//on scene load

		while (m_active)
		{
			m_key->update();

			this->update();				//update global scene

			m_sceneList[m_sceneID].update();			//update scene

			m_window->render();

			SDL_Delay(16);
			std::cout << "Frame updated." << std::endl;

			if (m_key->checkKeyDown(SDL_SCANCODE_ESCAPE))
			{
				m_active = false;
			}
		}
		std::cout << "Break game loop." << std::endl;
		m_window->reset();
		return true;
	}
}