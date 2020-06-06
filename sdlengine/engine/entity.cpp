#include "stdinclude.h"
#include "gameObject.h"
#include "window.h"

namespace simpleEngine
{
	entity::entity()
	{
		m_active = false;
		m_gameObjectName = "";
		m_loadFunction, m_updateFunction, m_sprite = nullptr;
		m_xPosition, m_yPosition = 0;

		onLoad();
	}

	entity::entity(const std::string& entityName)
	{
		m_active = true;
		m_gameObjectName = entityName;
		m_loadFunction, m_updateFunction, m_sprite = nullptr;
		m_xPosition, m_yPosition = 0;

		onLoad();
	}

	entity::entity(const std::string& entityName, std::function<void()> loadFunction, std::function<void()> updateFunction)
	{
		m_active = true;
		m_gameObjectName = entityName;
		m_loadFunction = loadFunction;
		m_updateFunction = updateFunction;
		m_sprite = nullptr;
		m_xPosition, m_yPosition = 0;

		onLoad();
	}

	entity::~entity()
	{
		std::cout << "Entity " << m_gameObjectName << " deleted." << std::endl;
	}

	bool entity::loadSprite(const std::string& imagePath)
	{
		m_sprite = IMG_Load(imagePath.c_str());
		return true;
	}

	void entity::updateSprite()
	{
		globalWindow.renderImage(m_sprite, m_xPosition, m_yPosition);
	}

	void entity::updateGameObject()
	{
		std::cout << "Entity " << m_gameObjectName << " updated." << std::endl;

		if (m_updateFunction != nullptr && m_active)
		{
			m_updateFunction();
		}
		if (m_sprite != nullptr)
		{
			updateSprite();
		}
	}

	void entity::move(int xDistance, int yDistance)
	{
		m_xPosition += xDistance;
		m_yPosition += yDistance;
	}
}