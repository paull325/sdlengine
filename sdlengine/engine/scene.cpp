#include "stdinclude.h"
#include "scene.h"
#include "gameObject.h"

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
			}
		}
	}

	/*			GAMEOBJECT				*/
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