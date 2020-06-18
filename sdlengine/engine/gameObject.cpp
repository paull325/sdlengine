#include "stdinclude.h"
#include "entity.h"
#include "window.h"
#include "globalScene.h"
namespace simpleEngine
{
	gameObject::gameObject()
	{
		m_active = false;
		m_name = "";
	}

	gameObject::gameObject(globalScene* g)
	{
		m_active = false;
		m_name = "";
		m_global = g;

		std::cout << "Game object " << m_name << " loaded." << std::endl;
	}

	gameObject::gameObject(globalScene* g, const std::string& name)
	{
		m_active = true;
		m_name = name;
		m_global = g;

		std::cout << "Game object " << m_name << " loaded." << std::endl;
	}

	gameObject::~gameObject()
	{
		std::cout << "Game object " << m_name << " deleted." << std::endl;
	}

	void gameObject::update()
	{
		std::cout << "Game object " << m_name << " updated." << std::endl;

		if (m_sprite != nullptr)		// only update sprite when loaded
		{
			this->updateSprite();
		}
	}

	bool gameObject::loadSprite(const std::string& imagePath)
	{
		m_sprite = IMG_Load(imagePath.c_str());
		return true;
	}

	void gameObject::updateSprite()
	{
		m_global->getWindow()->renderImage(m_sprite, m_xPosition, m_yPosition);
	}
}