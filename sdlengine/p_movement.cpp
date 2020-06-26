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
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_W) && !COLLISION_TOP)
			{
				m_geometry->move(0, -m_geometry->yVel());
			}
			else if (m_global->key()->checkKeyDown(SDL_SCANCODE_S) && !COLLISION_BOTTOM)
			{
				m_geometry->move(0, m_geometry->yVel());
			}
		}
		/* horizontal movement */
		if (!(m_global->key()->checkKeyDown(SDL_SCANCODE_A) && m_global->key()->checkKeyDown(SDL_SCANCODE_D)))
		{
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_A) && !COLLISION_LEFT)
			{
				m_geometry->move(-m_geometry->xVel(), 0);
			}
			if (m_global->key()->checkKeyDown(SDL_SCANCODE_D) && !COLLISION_RIGHT)
			{
				m_geometry->move(m_geometry->xVel(), 0);
			}
		}
	}
}