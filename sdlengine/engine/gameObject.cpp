#include "stdinclude.h"
#include "gameObject.h"
#include "geometry.h"
#include "window.h"
#include "globalScene.h"

namespace simpleEngine
{
	gameObject::gameObject()
	{
		m_layer = 0;
		m_active = false;
		m_name = "";
		m_geometry = std::make_shared<geometryObject>(0, 0, 0, 0);
	}

	gameObject::gameObject(globalScene* g)
	{
		m_layer = 0;
		m_active = false;
		m_name = "";
		m_global = g;
		m_geometry = std::make_shared<geometryObject>(0, 0, 0, 0);

		std::cout << "Game object " << m_name << " loaded." << std::endl;
	}

	gameObject::gameObject(globalScene* g, const std::string& name)
	{
		m_layer = 0;
		m_active = true;
		m_name = name;
		m_global = g;
		m_geometry = std::make_shared<geometryObject>(0, 0, 0, 0);

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
		m_global->getWindow()->renderImage(m_sprite, m_geometry, m_xTile, m_yTile, LOOK_DIR);
	}
}