#include "stdinclude.h"
#include "scene.h"
#include "gameObject.h"
#include "player.h"

namespace simpleEngine
{
	scene::~scene()
	{
		std::cout << "Scene " << sceneName() << " unloaded." << std::endl;
	}

	void scene::load()
	{
		std::cout << "Scene " << m_sceneName << " loaded." << std::endl;
	}

	void scene::update()
	{
		std::cout << "Scene " << m_sceneName << " updated." << std::endl;

		if (m_gameObjectList.size() != 0)			// update game objects
		{
			for (int i = 0; i < m_gameObjectList.size(); i++)
			{
				m_gameObjectList[i]->update();
				this->updateCollisionFlags(m_gameObjectList[i]);
			}
		}
	}

	const gameObjectPtr scene::getGameObjectByName(const std::string& gameObjectName)
	{
		for (int i = 0; i < m_gameObjectList.size(); i++)
		{
			if (m_gameObjectList[i]->name() == gameObjectName)
			{
				return m_gameObjectList[i];
			}
		}
		return nullptr;
	}

	void scene::updateCollisionFlags(gameObjectPtr obj)
	{
		m_player->COLLISION_LEFT = false;
		m_player->COLLISION_RIGHT = false;

		if (m_player->geometry()->x() + 5 > obj->geometry()->x()
			&& m_player->geometry()->x() - 5 < obj->geometry()->x() + obj->geometry()->xSize()
			&& m_player->geometry()->y() < obj->geometry()->y() + obj->geometry()->ySize()
			&& m_player->geometry()->y() + m_player->geometry()->ySize() > obj->geometry()->y())
		{
			m_player->COLLISION_LEFT = true;
		}

		if (m_player->geometry()->x() + m_player->geometry()->xSize() + 5 > obj->geometry()->x()
			&& m_player->geometry()->x() + m_player->geometry()->xSize() - 5 < obj->geometry()->x() + obj->geometry()->xSize()
			&& m_player->geometry()->y() < obj->geometry()->y() + obj->geometry()->ySize()
			&& m_player->geometry()->y() + m_player->geometry()->ySize() > obj->geometry()->y())
		{
			m_player->COLLISION_RIGHT = true;
		}
	}
}