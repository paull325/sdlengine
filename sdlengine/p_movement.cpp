#include "stdinclude.h"
#include "player.h"
#include "keyListener.h"
#include "globalScene.h"
#include "window.h"

namespace simpleEngine
{
	void player::doMovement()
	{
		/* vertical movement */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_W) && m_global->key()->checkKeyDown(SDL_SCANCODE_S)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_W))
			{
				m_geometry->move(0, -5);
			}
			else if (m_global->key()->checkKeyDown(SDL_SCANCODE_S))
			{
				m_geometry->move(0, 5);
			}
		}
		/* horizontal movement */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_A) && m_global->key()->checkKeyDown(SDL_SCANCODE_D)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_A) && !COLLISION_LEFT)
			{
				m_geometry->move(-5, 0);
			}
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_D) && !COLLISION_RIGHT)
			{
				m_geometry->move(5, 0);
			}
		}
	}
}