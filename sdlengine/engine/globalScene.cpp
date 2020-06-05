#include <engine.h>

namespace simpleEngine
{
	globalScene::globalScene()
	{
		m_sceneID = 0;
		if (!init())
		{
			std::cout << "Initialization failed." << std::endl;
		}
		else
		{
			std::cout << "Global scene " << sceneName() << " initialized." << std::endl;
		}
	}

	globalScene::~globalScene()
	{

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

		m_sceneList[m_sceneID].onLoad();
		while (m_active)
		{
			m_sceneList[m_sceneID].update();

			if (m_gameObjectList.size() != 0) // update global game objects
			{
				for (int i = 0; i < m_gameObjectList.size(); i++)
				{
					m_gameObjectList[i].updateGameObject();
				}
			}

			if (m_sceneList[m_sceneID].getGameObjectListSize() != 0) // update local game objects
			{
				for (int i = 0; i < m_sceneList[m_sceneID].getGameObjectListSize(); i++)
				{
					m_sceneList[m_sceneID].getGameObjectById(i)->updateGameObject();
				}
			}
			SDL_Delay(50);
			std::cout << "Frame updated." << std::endl;
		}
		std::cout << "Break game loop." << std::endl;
		return true;
	}
}