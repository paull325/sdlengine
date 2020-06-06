#include "stdinclude.h"
#include "globalScene.h"
#include "gameObject.h"
#include "window.h"

namespace simpleEngine
{
	globalScene::globalScene()
	{
		m_sceneID = 0;
		std::cout << "Global scene " << sceneName() << " initialized." << std::endl;
	}

	globalScene::~globalScene()
	{

	}

	void globalScene::end()
	{
		m_active = false;
	}

	bool globalScene::addScene(scene& sc)
	{
		try
		{
			m_sceneList.emplace_back(std::move(sc));
		}
		catch (std::bad_alloc& exception)
		{
			return false;
		}
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
		return &m_sceneList[id];
	}

	bool globalScene::start()
	{
		m_active = true;

		if (m_sceneList.size() == 0)
		{
			return false;
		}

		m_sceneList[m_sceneID].onLoad();				//on scene load

		while (m_active)
		{
			m_sceneList[m_sceneID].update();			//update scene

			if (m_gameObjectList.size() != 0)			// update global game objects
			{
				for (int i = 0; i < m_gameObjectList.size(); i++)
				{
					m_gameObjectList[i]->updateGameObject();
				}
			}
			if (m_entityList.size() != 0)			// update global entities
			{
				for (int i = 0; i < m_entityList.size(); i++)
				{
					m_entityList[i]->updateGameObject();
				}
			}
			if (m_sceneList[m_sceneID].gameObjectListSize() != 0) // update local game objects
			{
				for (int i = 0; i < m_sceneList[m_sceneID].gameObjectListSize(); i++)
				{
					m_sceneList[m_sceneID].getGameObjectById(i)->updateGameObject();
				}
			}
			if (m_sceneList[m_sceneID].entityListSize() != 0) // update local entities
			{
				for (int i = 0; i < m_sceneList[m_sceneID].entityListSize(); i++)
				{
					m_sceneList[m_sceneID].getEntityById(i)->updateGameObject();
				}
			}
			SDL_Delay(16);
			std::cout << "Frame updated." << std::endl;
		}
		std::cout << "Break game loop." << std::endl;
		globalWindow.reset();
		return true;
	}
}