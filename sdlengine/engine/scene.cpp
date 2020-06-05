#include "stdinclude.h"
#include "scene.h"
#include "gameObject.h"

namespace simpleEngine
{
	scene::scene()
	{
		if (!init())
		{
			std::cout << "Initialization failed." << std::endl;
		}
		else
		{
			std::cout << "Scene" << sceneName() << " initialized." << std::endl;
		}	
	}

	scene::scene(const std::string& sceneName, std::function<void()> loadFunction, std::function<void()> updateFunction)
	{
		m_sceneName = sceneName;
		m_loadFunction = loadFunction;
		m_updateFunction = updateFunction;

		if (!init())
		{
			std::cout << "Initialization failed." << std::endl;
		}
	}

	scene::~scene()
	{
		std::cout << "Scene " << sceneName() << " unloaded." << std::endl;
	}

	bool scene::init()
	{
		m_active = true;
		return true;
	}

	std::string scene::sceneName()
	{
		return m_sceneName;
	}

	void scene::setSceneName(const std::string& sceneName)
	{
		m_sceneName = sceneName;
	}

	void scene::end()
	{
		m_active = false;
	}

	bool scene::addGameObject(gameObject& obj)
	{
		try
		{
			m_gameObjectList.emplace_back(std::move(obj));
		}
		catch (std::bad_alloc& exception)
		{
			return false;
		}
		return true;
	}

	gameObject* scene::getGameObjectByName(const std::string& gameObjectName)
	{
		for (int i = 0; i < m_gameObjectList.size(); i++)
		{
			if (m_gameObjectList[i].gameObjectName() == gameObjectName)
			{
				return &m_gameObjectList[i];

			}
		}
		return nullptr;
	}

	gameObject* scene::getGameObjectById(int id)
	{
		return &m_gameObjectList[id];
	}

	size_t scene::getGameObjectListSize()
	{
		return m_gameObjectList.size();
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
		m_updateFunction();
	}
}