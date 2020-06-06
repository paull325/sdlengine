#include "stdinclude.h"
#include "gameObject.h"

namespace simpleEngine
{
	gameObject::gameObject()
	{
		m_active = false;
		m_gameObjectName = "";
		m_loadFunction, m_updateFunction = nullptr;

		onLoad();
	}

	gameObject::gameObject(const std::string& gameObjectName)
	{
		m_active = true;
		m_gameObjectName = gameObjectName;
		m_loadFunction, m_updateFunction = nullptr;

		onLoad();
	}

	gameObject::gameObject(const std::string& gameObjectName, std::function<void()> loadFunction, std::function<void()> updateFunction)
	{
		m_active = true;
		m_gameObjectName = gameObjectName;
		m_loadFunction = loadFunction;
		m_updateFunction = updateFunction;

		onLoad();
	}

	gameObject::~gameObject()
	{
		std::cout << "Game object " << m_gameObjectName << " deleted." << std::endl;
	}

	std::string gameObject::gameObjectName()
	{
		return m_gameObjectName;
	}

	void gameObject::setGameObjectName(const std::string& gameObjectName)
	{
		m_gameObjectName = gameObjectName;
	}

	void gameObject::onLoad()
	{
		std::cout << "Game object " << m_gameObjectName << " loaded." << std::endl;

		if (m_loadFunction != nullptr)
		{
			m_loadFunction();
		}
	}

	void gameObject::setUpdateFunction(std::function<void()> updateFunction)
	{
		m_updateFunction = updateFunction;
	}

	void gameObject::updateGameObject()
	{
		std::cout << "Game object " << m_gameObjectName << " updated." << std::endl;

		if (m_updateFunction != nullptr && m_active)
		{
			m_updateFunction();
		}
	}

	void gameObject::activate()
	{
		m_active = true;
	}

	void gameObject::deactivate()
	{
		m_active = false;
	}
}