#include "stdinclude.h"
#include "scene.h"
#include "entity.h"

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

		if (m_playerList.size() != 0)			// update player
		{
			for (int i = 0; i < m_playerList.size(); i++)
			{
				m_playerList[i]->update();
			}
		}
		if (m_gameObjectList.size() != 0)			// update game objects
		{
			for (int i = 0; i < m_gameObjectList.size(); i++)
			{
				m_gameObjectList[i]->update();
			}
		}
	}

	/*			PLAYER				*/
	bool scene::addPlayer(player& p)
	{
		m_playerList.emplace_back(std::make_shared<simpleEngine::player>(std::move(p)));
		return true;
	}
	/*			END	PLAYER			*/

	/*			GAMEOBJECT				*/
	bool scene::addGameObject(gameObject& obj)
	{
		m_gameObjectList.emplace_back( std::make_shared<simpleEngine::gameObject>(std::move(obj)) );
		return true;
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
	/*			END	GAMEOBJECT			*/
}