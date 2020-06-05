#include <engine.h>

namespace simpleEngine
{
	scene::scene()
	{
		if (!init())
			std::cout << "Initialization failed." << std::endl;
	}

	scene::scene(std::string sceneName, void(*loadFunction)(), void(*updateFunction)())
	{
		m_sceneName = sceneName;
		m_loadFunction = loadFunction;
		m_updateFunction = updateFunction;

		if (!init())
			std::cout << "Initialization failed." << std::endl;
	}

	scene::~scene()
	{
		std::cout << "Scene " << sceneName() << " unloaded." << std::endl;
	}

	bool scene::init()
	{
		m_active = true;
		std::cout << "Scene" << sceneName() << " initialized." << std::endl;
		return true;
	}

	std::string scene::sceneName()
	{
		return m_sceneName;
	}

	void scene::setSceneName(const std::string sceneName)
	{
		m_sceneName = sceneName;
	}

	void scene::end()
	{
		m_active = false;
	}

	bool scene::addGameObject(gameObject obj)
	{
		try
		{
			m_gameObjectList.push_back(obj);
		}
		catch (std::bad_alloc& exception)
		{
			return false;
		}
		return true;
	}

	gameObject* scene::getGameObjectByName(const std::string gameObjectName)
	{
		for (int i = 0; i < m_gameObjectList.size(); i++)
		{
			if (m_gameObjectList[i].gameObjectName() == gameObjectName)
			{
				return &m_gameObjectList[i];

			}
		}
	}

	gameObject* scene::getGameObjectById(unsigned int id)
	{
		return &m_gameObjectList[id];
	}

	unsigned int scene::getGameObjectListSize()
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