#include "stdinclude.h"
#include "player.h"
#include "globalScene.h"
#include "window.h"

namespace simpleEngine
{
	player::player(globalScene* g)
	{
		m_active = true;
		m_name = "";
		m_global = g;

		std::cout << "Player loaded." << std::endl;
	}

	player::~player()
	{
		std::cout << "Player deleted." << std::endl;
	}

	void player::update()
	{
		std::cout << "Player updated." << std::endl;

		this->doMovement();

		if (m_sprite != nullptr)		// only update sprite when loaded
		{
			this->updateSprite();
		}
	}
}