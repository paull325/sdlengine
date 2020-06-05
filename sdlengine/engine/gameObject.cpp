#include "stdinclude.h"
#include "gameObject.h"

namespace simpleEngine
{
	gameObject::gameObject(const std::string& gameObjectName)
	{
		m_gameObjectName = gameObjectName;
		m_loadFunction = nullptr;
		m_updateFunction = nullptr;

		onLoad();
	}

	gameObject::gameObject(const std::string& gameObjectName, std::function<void()> loadFunction, std::function<void()> updateFunction)
	{
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

		m_updateFunction();
	}
}