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

				this->updateCollisionFlags(m_gameObjectList[i], i);
				m_gameObjectList[i]->update();
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

	void scene::updateCollisionFlags(gameObjectPtr obj, int i_)
	{
		obj->COLLISION_LEFT = false;
		obj->COLLISION_RIGHT = false;
		obj->COLLISION_TOP = false;
		obj->COLLISION_BOTTOM = false;

		for (int i = 0; i < m_gameObjectList.size(); i++)
		{
			if (i == i_)
			{
				continue;
			}

			if (obj->geometry()->y() + obj->geometry()->ySize() > m_gameObjectList[i]->geometry()->y() && obj->geometry()->y() < m_gameObjectList[i]->geometry()->y() + m_gameObjectList[i]->geometry()->ySize())
			{
				if (obj->geometry()->x() - obj->geometry()->xVel() < m_gameObjectList[i]->geometry()->x() + m_gameObjectList[i]->geometry()->xSize())
				{
					obj->COLLISION_LEFT = true;
				}
			}

			/*if (obj->geometry()->x() - obj->geometry()->xVel() < m_gameObjectList[i]->geometry()->x() + m_gameObjectList[i]->geometry()->xSize())
			{
				obj->COLLISION_RIGHT = true;
			}
			else
			{
				obj->COLLISION_RIGHT = false;
			}

			if (obj->geometry()->y() + obj->geometry()->ySize() + obj->geometry()->yVel() > m_gameObjectList[i]->geometry()->y())
			{
				obj->COLLISION_TOP = true;
			}
			else
			{
				obj->COLLISION_TOP = false;
			}

			if (obj->geometry()->y() - obj->geometry()->yVel() < m_gameObjectList[i]->geometry()->y() + m_gameObjectList[i]->geometry()->ySize())
			{
				obj->COLLISION_BOTTOM = true;
			}
			else
			{
				obj->COLLISION_BOTTOM = false;
			}*/

			/*if (m_player->geometry()->x() + m_player->geometry()->xSize() + 5 > obj->geometry()->x()
				&& m_player->geometry()->x() + m_player->geometry()->xSize() - 5 < obj->geometry()->x() + obj->geometry()->xSize()
				&& m_player->geometry()->y() < obj->geometry()->y() + obj->geometry()->ySize()
				&& m_player->geometry()->y() + m_player->geometry()->ySize() > obj->geometry()->y())
			{
				m_player->COLLISION_RIGHT = true;
			}*/
		}
	}
}