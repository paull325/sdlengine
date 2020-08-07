#include "stdinclude.h"
#include "player.h"
#include "globalScene.h"
#include "window.h"

namespace simpleEngine
{
	player::player()
	{
		m_active = true;
		m_name = "_PLAYER";
		std::cout << "Player loaded." << std::endl;
	}

	player::player(globalScene* g)
	{
		m_active = true;
		m_name = "_PLAYER";
		m_global = g;
		m_geometry->xVel(0);
		m_geometry->yVel(0);
		m_geometry->xAcc(1);
		m_geometry->yAcc(1);

		walking.global(m_global);

		std::cout << "Player loaded." << std::endl;
	}

	player::~player()
	{
		std::cout << "Player deleted." << std::endl;
	}

	void player::animate()
	{
		switch (m_anim)
		{
			case IDLE:
				m_xTile = walking.playAnimation(12);
				break;
			case WALKING:
				m_xTile = walking.playAnimation(4);
				break;
		}
	}

	void player::update()
	{
		std::cout << "Player updated." << std::endl;

		this->doMovement();

		if (m_sprite != nullptr)		// only update sprite when loaded
		{
			this->animate();
			this->updateSprite();
		}
	}
}