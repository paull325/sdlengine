#include "stdinclude.h"
#include "entity.h"
#include "globalScene.h"
#include "window.h"

namespace simpleEngine
{
	player::player(globalScene* g)
	{
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

		/* vertical movement */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_W) && m_global->key()->checkKeyDown(SDL_SCANCODE_S)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_W))
			{
				this->move(0, -5);
			}
			else if (m_global->key()->checkKeyDown(SDL_SCANCODE_S))
			{
				this->move(0, 5);
			}
		}
		/* horizontal movement */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_A) && m_global->key()->checkKeyDown(SDL_SCANCODE_D)))
		{
			if(m_global->key()->checkKeyDown(SDL_SCANCODE_A))
			{
				this->move(-5, 0);
			}
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_D))
			{
				this->move(5, 0);
			}
		}

		if (m_sprite != nullptr)		// only update sprite when loaded
		{
			this->updateSprite();
		}
	}

	void player::updateSprite()
	{
		m_global->getWindow()->renderImage(m_sprite, m_xPosition, m_yPosition);
	}
}