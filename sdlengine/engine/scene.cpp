#include "stdinclude.h"
#include "scene.h"
#include "gameObject.h"

namespace simpleEngine
{
	scene::scene()
	{
		m_sceneName = "";
		m_loadFunction, m_updateFunction = nullptr;
		m_active = true;
	}

	scene::scene(const std::string& sceneName, std::function<void()> loadFunction, std::function<void()> updateFunction)
	{
		m_sceneName = sceneName;
		m_loadFunction = loadFunction;
		m_updateFunction = updateFunction;
		m_active = true;
	}

	scene::~scene()
	{
		std::cout << "Scene " << sceneName() << " unloaded." << std::endl;
	}

	std::string scene::sceneName()
	{
		return m_sceneName;
	}

	void scene::setSceneName(const std::string& sceneName)
	{
		m_sceneName = sceneName;
	}

	void scene::onLoad()
	{
		std::cout << "Scene " << m_sceneName << " loaded." << std::endl;

		if (m_loadFunction != nullptr)
		{
			m_loadFunction();
		}
	}

	void scene::update()
	{
		if (m_updateFunction != nullptr)
		{
			m_updateFunction();
		}
	}

	void scene::end()
	{
		m_active = false;
	}

	/*			GAMEOBJECT				*/
	bool scene::addGameObject(gameObject& obj)
	{
		try
		{
			m_gameObjectList.emplace_back( std::make_shared<simpleEngine::gameObject>(std::move(obj)) );
		}
		catch (std::bad_alloc& exception)
		{
			return false;
		}
		return true;
	}

	gameObjectPtr scene::getGameObjectByName(const std::string& gameObjectName)
	{
		for (int i = 0; i < m_gameObjectList.size(); i++)
		{
			if (m_gameObjectList[i]->gameObjectName() == gameObjectName)
			{
				return m_gameObjectList[i];
			}
		}
		return nullptr;
	}

	gameObjectPtr scene::getGameObjectById(int id)
	{
		return m_gameObjectList[id];
	}

	size_t scene::gameObjectListSize()
	{
		return m_gameObjectList.size();
	}
	/*			END	GAMEOBJECT			*/

	/*				ENTITY				*/
	bool scene::addEntity(entity& obj)
	{
		try
		{
			m_entityList.emplace_back(std::make_shared<simpleEngine::entity>(std::move(obj)));
		}
		catch (std::bad_alloc& exception)
		{
			return false;
		}
		return true;
	}

	entityPtr scene::getEntityByName(const std::string& gameObjectName)
	{
		for (int i = 0; i < m_entityList.size(); i++)
		{
			if (m_entityList[i]->gameObjectName() == gameObjectName)
			{
				return m_entityList[i];
			}
		}
		return nullptr;
	}

	entityPtr scene::getEntityById(int id)
	{
		return m_entityList[id];
	}

	size_t scene::entityListSize()
	{
		return m_entityList.size();
	}
	/*			END ENTITY					*/
}